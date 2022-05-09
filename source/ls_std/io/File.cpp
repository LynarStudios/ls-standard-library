/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/File.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>
#include <ls_std/io/FilePathSeparatorMatch.hpp>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <sys/stat.h>

#if defined(unix) || defined(__APPLE__)

#include <unistd.h>

#endif

#ifdef _WIN32

#include <direct.h>
#include <tchar.h>

#endif

ls::File::File(::std::string _absoluteFilePath)
    : ls::std::core::Class("File"),
      absoluteFilePath(ls::File::_normalizePath(::std::move(_absoluteFilePath)))
{}

bool ls::File::operator==(ls::File &_file)
{
  return ls::File::_equals(*this, _file);
}

bool ls::File::operator!=(ls::File &_file)
{
  return !ls::File::_equals(*this, _file);
}

bool ls::File::canExecute()
{
  return ls::File::_isExecutable(this->absoluteFilePath);
}

bool ls::File::canRead()
{
  bool readable;

  #if defined(unix) || defined(__APPLE__)
  readable = ls::File::_isReadableUnix(this->absoluteFilePath);
  #endif
  #ifdef _WIN32
  readable = ls::File::_isReadableWindows(this->absoluteFilePath);
  #endif

  return readable;
}

bool ls::File::canWrite()
{
  return ls::File::_isWritable(this->absoluteFilePath);
}

void ls::File::createNewFile()
{
  if (!ls::File::_exists(this->absoluteFilePath))
  {
    ::std::ofstream file{this->absoluteFilePath};
    file.close();
  }
  else
  {
    throw ls::std::core::FileOperationException{};
  }
}

bool ls::File::exists()
{
  return ls::File::_exists(this->absoluteFilePath);
}

std::string ls::File::getAbsoluteFilePath()
{
  return this->absoluteFilePath;
}

std::string ls::File::getName()
{
  ::std::string copy = this->absoluteFilePath;

  // if it's a directory, remove separator from end, if it does exist

  if (ls::File::_isDirectory(this->absoluteFilePath))
  {
    copy.erase(::std::remove_if(copy.end() - 1, copy.end(), ls::FilePathSeparatorMatch()), copy.end());
  }

  // now get the file / directory name

  auto base = ::std::find_if(copy.rbegin(), copy.rend(), ls::FilePathSeparatorMatch()).base();
  return ::std::string{base, copy.end()};
}

std::string ls::File::getParent()
{
  return ls::File::_getParent(this->absoluteFilePath);
}

std::string ls::File::getWorkingDirectory()
{
  ::std::string workingDirectory{};

  #if defined(unix) || defined(__APPLE__)
  workingDirectory = ls::File::_getWorkingDirectoryUnix();
  #endif
  #ifdef _WIN32
  workingDirectory = ls::File::_getWorkingDirectoryWindows();
  #endif

  return workingDirectory;
}

long ls::File::getSize()
{
  ::std::streampos fileSize{};

  if (ls::File::_exists(this->absoluteFilePath))
  {
    ::std::ifstream fileHandler{this->absoluteFilePath, ::std::ios::in};
    fileSize = fileHandler.tellg();
    fileHandler.seekg(0, ::std::ios::end);
    fileSize = fileHandler.tellg() - fileSize;
    fileHandler.close();
  }

  return (long) fileSize;
}

bool ls::File::isDirectory()
{
  return ls::File::_isDirectory(this->absoluteFilePath);
}

bool ls::File::isFile()
{
  return ls::File::_isFile(this->absoluteFilePath);
}

time_t ls::File::lastModified()
{
  return ls::File::_lastModified(this->absoluteFilePath);
}

std::list<std::string> ls::File::list()
{
  ::std::list<::std::string> fileList{};

  if (ls::File::_isDirectory(this->absoluteFilePath))
  {
    fileList = ls::File::_list(this->absoluteFilePath);
  }

  return fileList;
}

std::list<std::string> ls::File::listFiles()
{
  ::std::list<::std::string> fileList{};

  if (ls::File::_isDirectory(this->absoluteFilePath))
  {
    fileList = ls::File::_listFiles(this->absoluteFilePath);
  }

  return fileList;
}

void ls::File::makeDirectory()
{
  if (ls::File::_mkdir(this->absoluteFilePath))
  {
    throw ls::std::core::FileOperationException{};
  }
}

void ls::File::makeDirectories()
{
  ::std::vector<::std::string> subDirectories = ls::File::_splitIntoSubDirectoryNames(this->absoluteFilePath);
  const char separator = ls::FilePathSeparator::get();
  ::std::string currentHierarchy{};

  for (const auto &subDirectory: subDirectories)
  {
    currentHierarchy += subDirectory;

    if (!ls::File::_exists(currentHierarchy))
    {
      ls::File::_mkdir(currentHierarchy);
    }

    currentHierarchy += separator;
  }
}

void ls::File::remove()
{
  if (ls::File::_isFile(this->absoluteFilePath))
  {
    ::std::remove(this->absoluteFilePath.c_str());
  }

  if (ls::File::_isDirectory(this->absoluteFilePath))
  {
    ls::File::_remove(this->absoluteFilePath);
  }
}

bool ls::File::renameTo(const ::std::string &_newName)
{
  bool renamed = ls::File::_renameTo(this->absoluteFilePath, _newName);

  if (renamed)
  {
    this->absoluteFilePath = _newName;
  }

  return renamed;
}

void ls::File::reset(const ::std::string &_newPath)
{
  this->absoluteFilePath = ls::File::_normalizePath(_newPath);
}

#ifdef _WIN32

void ls::File::_addToFileListWindows(const std::string &_path, bool _withDirectories, WIN32_FIND_DATA _data, std::list<std::string> &_list)
{
  const char separator = ls::FilePathSeparator::get();
  std::string absolutePath = _path + separator + _data.cFileName;

  if (_withDirectories)
  {
    _list.emplace_back(absolutePath);
  }
  else
  {
    if (ls::File::_isFile(absolutePath))
    {
      _list.emplace_back(absolutePath);
    }
  }
}

#endif

#if defined(unix) || defined(__APPLE__)

void ls::File::_addToFileListUnix(const ::std::string &_path, bool _withDirectories, dirent *directoryEntity, ::std::list<::std::string> &_list)
{
  const char separator = ls::FilePathSeparator::get();
  ::std::string absolutePath = _path + separator + directoryEntity->d_name;

  if (_withDirectories)
  {
    _list.emplace_back(absolutePath);
  }
  else
  {
    if (ls::File::_isFile(absolutePath))
    {
      _list.emplace_back(absolutePath);
    }
  }
}

#endif

bool ls::File::_equals(ls::File &_file, ls::File &_foreignFile)
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

bool ls::File::_exists(const ::std::string &_path)
{
  struct stat _stat{};
  return (stat(_path.c_str(), &_stat) == 0);
}

std::string ls::File::_getParent(const ::std::string &_path)
{
  ::std::string parent{};
  ::std::vector<::std::string> subDirectoryNames = ls::File::_splitIntoSubDirectoryNames(_path);
  const char separator = ls::FilePathSeparator::get();
  subDirectoryNames.pop_back();

  for (auto const &subDirectoryName: subDirectoryNames)
  {
    parent += subDirectoryName + separator;
  }

  return parent;
}

#if defined(unix) || defined(__APPLE__)

std::string ls::File::_getWorkingDirectoryUnix()
{
  ::std::string workingDirectory{};
  char buffer[PATH_MAX];

  if (getcwd(buffer, sizeof(buffer)) == nullptr)
  {
    throw ls::std::core::FileOperationException{};
  }
  else
  {
    workingDirectory = ::std::string(buffer);
  }

  return workingDirectory;
}

#endif

#ifdef _WIN32

std::string ls::File::_getWorkingDirectoryWindows()
{
  std::string workingDirectory{};
  TCHAR buffer[MAX_PATH];

  if (!GetCurrentDirectory(MAX_PATH, buffer))
  {
    throw ls::FileOperationException{};
  }
  else
  {
    workingDirectory = std::string(buffer);
  }

  return workingDirectory;
}

#endif

bool ls::File::_isDirectory(const ::std::string &_path)
{
  bool match{};
  struct stat _stat{};

  if (stat(_path.c_str(), &_stat) == 0)
  {
    match = _stat.st_mode & (unsigned short) S_IFDIR;
  }

  return match;
}

bool ls::File::_isExecutable(const ::std::string &_path)
{
  bool executable{};

  if (ls::File::_exists(_path))
  {
    struct stat _stat{};

    if (stat(_path.c_str(), &_stat) == 0)
    {
      executable = (_stat.st_mode & (unsigned short) S_IEXEC) != 0;
    }
  }

  return executable;
}

bool ls::File::_isFile(const ::std::string &_path)
{
  bool match{};
  struct stat _stat{};

  if (stat(_path.c_str(), &_stat) == 0)
  {
    match = _stat.st_mode & (unsigned) S_IFREG;
  }

  return match;
}

#if defined(unix) || defined(__APPLE__)

bool ls::File::_isReadableUnix(const ::std::string &_path)
{
  bool readable{};

  if (ls::File::_exists(_path))
  {
    struct stat _stat{};

    if (stat(_path.c_str(), &_stat) == 0)
    {
      readable = (_stat.st_mode & (unsigned) S_IREAD) != 0;
    }
  }
  else
  {
    throw ls::std::core::FileOperationException{};
  }

  return readable;
}

#endif

#ifdef _WIN32

bool ls::File::_isReadableWindows(const std::string &_path)
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
    throw ls::FileOperationException{};
  }

  return readable;
}

#endif

bool ls::File::_isWritable(const ::std::string &_path)
{
  bool writable{};

  if (ls::File::_exists(_path))
  {
    struct stat _stat{};

    if (stat(_path.c_str(), &_stat) == 0)
    {
      writable = (_stat.st_mode & (unsigned) S_IWRITE) != 0;
    }
  }

  return writable;
}

time_t ls::File::_lastModified(const ::std::string &_path)
{
  time_t lastModifiedTimeStamp{};
  struct stat _stat{};

  if (stat(_path.c_str(), &_stat) == 0)
  {
    lastModifiedTimeStamp = _stat.st_mtime;
  }

  return lastModifiedTimeStamp;
}

std::list<std::string> ls::File::_list(const ::std::string &_path)
{
  ::std::list<::std::string> filesInDirectory{};

  #if defined(unix) || defined(__APPLE__)
  filesInDirectory = ls::File::_listUnix(_path, true);
  #endif
  #ifdef _WIN32
  filesInDirectory = ls::File::_listWindows(_path, true);
  #endif

  return filesInDirectory;
}

std::list<std::string> ls::File::_listFiles(const ::std::string &_path)
{
  ::std::list<::std::string> filesInDirectory{};

  #if defined(unix) || defined(__APPLE__)
  filesInDirectory = ls::File::_listUnix(_path, false);
  #endif
  #ifdef _WIN32
  filesInDirectory = ls::File::_listWindows(_path, false);
  #endif

  return filesInDirectory;
}

#if defined(unix) || defined(__APPLE__)

std::list<std::string> ls::File::_listUnix(const ::std::string &_path, bool withDirectories)
{
  ::std::list<::std::string> filesInDirectory{};
  DIR *directory = opendir(_path.c_str());
  struct dirent *directoryEntity;
  ::std::string absolutePath{};

  while ((directoryEntity = readdir(directory)) != nullptr)
  {
    ls::File::_addToFileListUnix(_path, withDirectories, directoryEntity, filesInDirectory);
  }

  closedir(directory);
  return filesInDirectory;
}

#endif

#ifdef _WIN32

std::list<std::string> ls::File::_listWindows(const std::string &_path, bool withDirectories)
{
  std::list<std::string> filesInDirectory{};
  WIN32_FIND_DATA data{};
  HANDLE hFind;
  std::string pattern{_path + ls::FilePathSeparator::get() + "*"};

  if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
  {
    do
    {
      ls::File::_addToFileListWindows(_path, withDirectories, data, filesInDirectory);
    } while (FindNextFile(hFind, &data) != 0);

    FindClose(hFind);
  }

  return filesInDirectory;
}

#endif

int ls::File::_mkdir(const ::std::string &_path)
{
  int result;

  #ifdef _WIN32
  result = mkdir(_path.c_str());
  #endif

  #if defined(unix) || defined(__APPLE__)
  result = mkdir(_path.c_str(), 0777);
  #endif

  return result;
}

std::string ls::File::_normalizePath(::std::string _path)
{
  _path = ls::File::_replaceWrongSeparator(_path);
  _path = ls::File::_reduceSeparators(_path);

  return _path;
}

std::string ls::File::_reduceSeparators(const ::std::string &_path)
{
  static const char separator = {ls::FilePathSeparator::get()};
  ::std::string normalizedPath{};
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

void ls::File::_remove(const ::std::string &_path)
{
  #if defined(unix) || defined(__APPLE__)
  ls::File::_removeUnix(_path);
  #endif
  #ifdef _WIN32
  ls::File::_removeWindows(_path);
  #endif
}

#if defined(unix) || defined(__APPLE__)

void ls::File::_removeUnix(const ::std::string &_path)
{
  rmdir(_path.c_str());
}

#endif

#ifdef _WIN32

void ls::File::_removeWindows(const std::string &_path)
{
  _rmdir(_path.c_str());
}

#endif

bool ls::File::_renameTo(const ::std::string &_oldName, const ::std::string &_newName)
{
  return ::std::rename(_oldName.c_str(), _newName.c_str()) == 0;
}

std::string ls::File::_replaceWrongSeparator(::std::string _path)
{
  static const char unixSeparator = ls::FilePathSeparator::getUnixFilePathSeparator();
  static const char windowsSeparator = ls::FilePathSeparator::getWindowsFilePathSeparator();

  #if defined(unix) || defined(__APPLE__)
  ::std::replace(_path.begin(), _path.end(), windowsSeparator, unixSeparator);
  #endif

  #ifdef _WIN32
  std::replace(_path.begin(), _path.end(), unixSeparator, windowsSeparator);
  #endif

  return _path;
}

std::vector<std::string> ls::File::_splitIntoSubDirectoryNames(const ::std::string &_path)
{
  ::std::vector<::std::string> subDirectoryNames{};
  ::std::stringstream _stream{_path};
  ::std::string subDirectoryName{};
  const char separator = ls::FilePathSeparator::get();

  while (::std::getline(_stream, subDirectoryName, separator))
  {
    subDirectoryNames.push_back(subDirectoryName);
  }

  return subDirectoryNames;
}
