/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-23
 *
 * */

#include <algorithm>
#include <cstdio>
#ifdef _WIN32
  #include <direct.h>
#endif
#include <fstream>
#include <list>
#include <ls-std/core/exception/FileOperationException.hpp>
#include <ls-std/io/File.hpp>
#include <ls-std/io/FilePathSeparator.hpp>
#include <ls-std/io/FilePathSeparatorMatch.hpp>
#include <sstream>
#include <sys/stat.h>
#ifdef _WIN32
  #include <tchar.h>
#endif
#if defined(unix) || defined(__APPLE__)
  #include <unistd.h>
#endif
#include <vector>

using ls::std::core::Class;
using ls::std::core::FileOperationException;
using ls::std::io::File;
using ls::std::io::FilePathSeparator;
using ls::std::io::FilePathSeparatorMatch;
using std::find_if;
using std::getline;
using std::ifstream;
using std::ios;
using std::list;
using std::move;
using std::ofstream;
using std::remove;
using std::remove_if;
using std::rename;
using std::replace;
using std::streampos;
using std::string;
using std::stringstream;
using std::vector;

File::File(string _absoluteFilePath) : Class("File"), absoluteFilePath(File::_normalizePath(::move(_absoluteFilePath)))
{}

File::~File() noexcept = default;

bool File::operator==(File &_file)
{
  return File::_equals(*this, _file);
}

bool File::operator!=(File &_file)
{
  return !File::_equals(*this, _file);
}

bool File::canExecute()
{
  return File::_isExecutable(this->absoluteFilePath);
}

bool File::canRead()
{
  bool readable{};

#if defined(unix) || defined(__APPLE__)
  readable = File::_isReadableUnix(this->absoluteFilePath);
#endif
#ifdef _WIN32
  readable = File::_isReadableWindows(this->absoluteFilePath);
#endif

  return readable;
}

bool File::canWrite()
{
  return File::_isWritable(this->absoluteFilePath);
}

void File::createNewFile()
{
  if (!File::_exists(this->absoluteFilePath))
  {
    ofstream file{this->absoluteFilePath};
    file.close();
  }
  else
  {
    throw FileOperationException{"operation: create new file"};
  }
}

bool File::exists()
{
  return File::_exists(this->absoluteFilePath);
}

string File::getAbsoluteFilePath()
{
  return this->absoluteFilePath;
}

string File::getName()
{
  string copy = this->absoluteFilePath;

  // if it's a directory, remove separator from end, if it does exist

  if (File::_isDirectory(this->absoluteFilePath))
  {
    copy.erase(remove_if(copy.end() - 1, copy.end(), FilePathSeparatorMatch()), copy.end());
  }

  // now get the file / directory name

  auto base = find_if(copy.rbegin(), copy.rend(), FilePathSeparatorMatch()).base();
  return string{base, copy.end()};
}

string File::getParent()
{
  return File::_getParent(this->absoluteFilePath);
}

string File::getWorkingDirectory()
{
  string workingDirectory{};

#if defined(unix) || defined(__APPLE__)
  workingDirectory = File::_getWorkingDirectoryUnix();
#endif
#ifdef _WIN32
  workingDirectory = File::_getWorkingDirectoryWindows();
#endif

  return workingDirectory;
}

long File::getSize()
{
  streampos fileSize{};

  if (File::_exists(this->absoluteFilePath))
  {
    ifstream fileHandler{this->absoluteFilePath, ios::in};
    fileSize = fileHandler.tellg();
    fileHandler.seekg(0, ios::end);
    fileSize = fileHandler.tellg() - fileSize;
    fileHandler.close();
  }

  return (long) fileSize;
}

bool File::isDirectory()
{
  return File::_isDirectory(this->absoluteFilePath);
}

bool File::isFile()
{
  return File::_isFile(this->absoluteFilePath);
}

time_t File::lastModified()
{
  return File::_lastModified(this->absoluteFilePath);
}

::list<string> File::list()
{
  ::list<string> fileList{};

  if (File::_isDirectory(this->absoluteFilePath))
  {
    fileList = File::_list(this->absoluteFilePath);
  }

  return fileList;
}

::list<string> File::listFiles()
{
  ::list<string> fileList{};

  if (File::_isDirectory(this->absoluteFilePath))
  {
    fileList = File::_listFiles(this->absoluteFilePath);
  }

  return fileList;
}

void File::makeDirectory()
{
  if (!File::_makeDirectory(this->absoluteFilePath))
  {
    throw FileOperationException{"operation: create directory"};
  }
}

void File::makeDirectories()
{
  vector<string> subDirectories = File::_splitIntoSubDirectoryNames(this->absoluteFilePath);
  const char separator = FilePathSeparator::get();
  string currentHierarchy{};

  for (const auto &subDirectory : subDirectories)
  {
    currentHierarchy += subDirectory;

    if (!File::_exists(currentHierarchy + separator) && !currentHierarchy.empty())
    {
      if (!File::_makeDirectory(currentHierarchy))
      {
        throw FileOperationException{"operation: create directory"};
      }
    }

    currentHierarchy += separator;
  }
}

void File::remove()
{
  if (File::_isFile(this->absoluteFilePath))
  {
    ::remove(this->absoluteFilePath.c_str());
  }

  if (File::_isDirectory(this->absoluteFilePath))
  {
    File::_remove(this->absoluteFilePath);
  }
}

bool File::renameTo(const string &_newName)
{
  bool renamed = File::_renameTo(this->absoluteFilePath, _newName);

  if (renamed)
  {
    this->absoluteFilePath = _newName;
  }

  return renamed;
}

void File::reset(const string &_newPath)
{
  this->absoluteFilePath = File::_normalizePath(_newPath);
}

#ifdef _WIN32

void File::_addToFileListWindows(const string &_path, bool _withDirectories, WIN32_FIND_DATA _data, ::list<string> &_list)
{
  const char separator = FilePathSeparator::get();
  string absolutePath = _path + separator + _data.cFileName;

  if (_withDirectories)
  {
    _list.emplace_back(absolutePath);
  }
  else
  {
    if (File::_isFile(absolutePath))
    {
      _list.emplace_back(absolutePath);
    }
  }
}

#endif

#if defined(unix) || defined(__APPLE__)

void File::_addToFileListUnix(const string &_path, bool _withDirectories, dirent *directoryEntity, ::list<string> &_list)
{
  const char separator = FilePathSeparator::get();
  string absolutePath = _path + separator + directoryEntity->d_name;

  if (_withDirectories)
  {
    _list.emplace_back(absolutePath);
  }
  else
  {
    if (File::_isFile(absolutePath))
    {
      _list.emplace_back(absolutePath);
    }
  }
}

#endif

bool File::_equals(File &_file, File &_foreignFile)
{
  bool isEqual = _file.getAbsoluteFilePath() == _foreignFile.getAbsoluteFilePath();

  if (_file.exists() && _foreignFile.exists())
  {
    isEqual = isEqual && _file.canRead() == _foreignFile.canRead();
    isEqual = isEqual && _file.canWrite() == _foreignFile.canWrite();
    isEqual = isEqual && _file.canExecute() == _foreignFile.canExecute();
  }

  return isEqual;
}

bool File::_exists(const string &_path)
{
  struct stat _stat
  {
  };
  return (stat(_path.c_str(), &_stat) == 0);
}

string File::_getParent(const string &_path)
{
  string parent{};
  vector<string> subDirectoryNames = File::_splitIntoSubDirectoryNames(_path);
  const char separator = FilePathSeparator::get();
  subDirectoryNames.pop_back();

  for (auto const &subDirectoryName : subDirectoryNames)
  {
    parent += subDirectoryName + separator;
  }

  return parent;
}

#if defined(unix) || defined(__APPLE__)

string File::_getWorkingDirectoryUnix()
{
  string workingDirectory{};
  char buffer[PATH_MAX];

  if (getcwd(buffer, sizeof(buffer)) == nullptr)
  {
    throw FileOperationException{"operation: get working directory"};
  }
  else
  {
    workingDirectory = string(buffer);
  }

  return workingDirectory;
}

#endif

#ifdef _WIN32

string File::_getWorkingDirectoryWindows()
{
  string workingDirectory{};
  TCHAR buffer[MAX_PATH];

  if (!GetCurrentDirectory(MAX_PATH, buffer))
  {
    throw FileOperationException{"operation: get working directory"};
  }
  else
  {
    workingDirectory = string(buffer);
  }

  return workingDirectory;
}

#endif

bool File::_isDirectory(const string &_path)
{
  bool match{};
  struct stat _stat
  {
  };

  if (stat(_path.c_str(), &_stat) == 0)
  {
    match = _stat.st_mode & (unsigned short) S_IFDIR;
  }

  return match;
}

bool File::_isExecutable(const string &_path)
{
  bool executable{};

  if (File::_exists(_path))
  {
    struct stat _stat
    {
    };

    if (stat(_path.c_str(), &_stat) == 0)
    {
      executable = (_stat.st_mode & (unsigned short) S_IEXEC) != 0;
    }
  }

  return executable;
}

bool File::_isFile(const string &_path)
{
  bool match{};
  struct stat _stat
  {
  };

  if (stat(_path.c_str(), &_stat) == 0)
  {
    match = _stat.st_mode & (unsigned) S_IFREG;
  }

  return match;
}

#if defined(unix) || defined(__APPLE__)

bool File::_isReadableUnix(const string &_path)
{
  bool readable{};

  if (File::_exists(_path))
  {
    struct stat _stat
    {
    };

    if (stat(_path.c_str(), &_stat) == 0)
    {
      readable = (_stat.st_mode & (unsigned) S_IREAD) != 0;
    }
  }
  else
  {
    throw FileOperationException{"operation: fetch permissions"};
  }

  return readable;
}

#endif

#ifdef _WIN32

bool File::_isReadableWindows(const string &_path)
{
  bool readable;
  WIN32_FIND_DATA data{};
  HANDLE handleFind = FindFirstFile(_path.c_str(), &data);

  if (handleFind != INVALID_HANDLE_VALUE)
  {
    readable = GetFileAttributes(data.cFileName) & (unsigned) FILE_ATTRIBUTE_READONLY;
  }
  else
  {
    throw FileOperationException{"operation: fetch permissions"};
  }

  return readable;
}

#endif

bool File::_isWritable(const string &_path)
{
  bool writable{};

  if (File::_exists(_path))
  {
    struct stat _stat
    {
    };

    if (stat(_path.c_str(), &_stat) == 0)
    {
      writable = (_stat.st_mode & (unsigned) S_IWRITE) != 0;
    }
  }

  return writable;
}

time_t File::_lastModified(const string &_path)
{
  time_t lastModifiedTimeStamp{};
  struct stat _stat
  {
  };

  if (stat(_path.c_str(), &_stat) == 0)
  {
    lastModifiedTimeStamp = _stat.st_mtime;
  }

  return lastModifiedTimeStamp;
}

::list<string> File::_list(const string &_path)
{
  ::list<string> filesInDirectory{};

#if defined(unix) || defined(__APPLE__)
  filesInDirectory = File::_listUnix(_path, true);
#endif
#ifdef _WIN32
  filesInDirectory = File::_listWindows(_path, true);
#endif

  return filesInDirectory;
}

::list<string> File::_listFiles(const string &_path)
{
  ::list<string> filesInDirectory{};

#if defined(unix) || defined(__APPLE__)
  filesInDirectory = File::_listUnix(_path, false);
#endif
#ifdef _WIN32
  filesInDirectory = File::_listWindows(_path, false);
#endif

  return filesInDirectory;
}

#if defined(unix) || defined(__APPLE__)

::list<string> File::_listUnix(const string &_path, bool withDirectories)
{
  ::list<string> filesInDirectory{};
  DIR *directory = opendir(_path.c_str());
  struct dirent *directoryEntity;
  string absolutePath{};

  while ((directoryEntity = readdir(directory)) != nullptr)
  {
    File::_addToFileListUnix(_path, withDirectories, directoryEntity, filesInDirectory);
  }

  closedir(directory);
  return filesInDirectory;
}

#endif

#ifdef _WIN32

::list<string> File::_listWindows(const string &_path, bool withDirectories)
{
  ::list<string> filesInDirectory{};
  WIN32_FIND_DATA data{};
  HANDLE hFind;
  string pattern{_path + FilePathSeparator::get() + "*"};

  if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
  {
    do
    {
      File::_addToFileListWindows(_path, withDirectories, data, filesInDirectory);
    } while (FindNextFile(hFind, &data) != 0);

    FindClose(hFind);
  }

  return filesInDirectory;
}

#endif

bool File::_makeDirectory(const string &_path)
{
  int result{};

#ifdef _WIN32
  result = _mkdir(_path.c_str());
#endif

#if defined(unix) || defined(__APPLE__)
  result = mkdir(_path.c_str(), 0777);
#endif

  return result == 0;
}

string File::_normalizePath(string _path)
{
  _path = File::_replaceWrongSeparator(_path);
  _path = File::_reduceSeparators(_path);

  return _path;
}

string File::_reduceSeparators(const string &_path)
{
  static const char separator = {FilePathSeparator::get()};
  string normalizedPath{};
  int index{};

  while (index < _path.size())
  {
    if (_path[index] == separator)
    {
      normalizedPath += _path[index];

      do
      {
        index++;
      } while (_path[index] == separator);
    }
    else
    {
      normalizedPath += _path[index];
      index++;
    }
  }

  return normalizedPath;
}

void File::_remove(const string &_path)
{
#if defined(unix) || defined(__APPLE__)
  File::_removeUnix(_path);
#endif
#ifdef _WIN32
  File::_removeWindows(_path);
#endif
}

#if defined(unix) || defined(__APPLE__)

void File::_removeUnix(const string &_path)
{
  rmdir(_path.c_str());
}

#endif

#ifdef _WIN32

void File::_removeWindows(const string &_path)
{
  _rmdir(_path.c_str());
}

#endif

bool File::_renameTo(const string &_oldName, const string &_newName)
{
  return rename(_oldName.c_str(), _newName.c_str()) == 0;
}

string File::_replaceWrongSeparator(string _path)
{
  static const char unixSeparator = FilePathSeparator::getUnixFilePathSeparator();
  static const char windowsSeparator = FilePathSeparator::getWindowsFilePathSeparator();

#if defined(unix) || defined(__APPLE__)
  replace(_path.begin(), _path.end(), windowsSeparator, unixSeparator);
#endif

#ifdef _WIN32
  replace(_path.begin(), _path.end(), unixSeparator, windowsSeparator);
#endif

  return _path;
}

vector<string> File::_splitIntoSubDirectoryNames(const string &_path)
{
  vector<string> subDirectoryNames{};
  stringstream _stream{_path};
  string subDirectoryName{};
  const char separator = FilePathSeparator::get();

  while (getline(_stream, subDirectoryName, separator))
  {
    subDirectoryNames.push_back(subDirectoryName);
  }

  return subDirectoryNames;
}
