/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-19
 *
 * */

#include "File.hpp"
#include "../exception/FileOperationException.hpp"
#include "FilePathSeparatorMatch.hpp"
#include <fstream>
#include <sys/stat.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>

#if defined(unix) || defined(__APPLE__)
#include <unistd.h>
#endif

ls_std::File::File(std::string _absoluteFilePath) : Class("File"),
absoluteFilePath(ls_std::File::_normalizePath(std::move(_absoluteFilePath)))
{}

// TODO: also compare executable, readable, writable flag
bool ls_std::File::operator==(File &_file)
{
  std::string normalizedForeignFilePath = ls_std::File::_normalizePath(_file.getAbsoluteFilePath());
  return this->absoluteFilePath == normalizedForeignFilePath;
}

bool ls_std::File::operator!=(File &_file)
{
  std::string normalizedForeignFilePath = ls_std::File::_normalizePath(_file.getAbsoluteFilePath());
  return this->absoluteFilePath != normalizedForeignFilePath;
}

bool ls_std::File::canExecute()
{
  return ls_std::File::_isExecutable(this->absoluteFilePath);
}

bool ls_std::File::canRead()
{
  bool readable;

  #if defined(unix) || defined(__APPLE__)
    readable = ls_std::File::_isReadableUnix(this->absoluteFilePath);
  #endif
  #ifdef _WIN32
    readable = ls_std::File::_isReadableWindows(this->absoluteFilePath);
  #endif

  return readable;
}

void ls_std::File::createNewFile()
{
  if(!ls_std::File::_exists(this->absoluteFilePath)) {
    std::ofstream file {this->absoluteFilePath};
    file.close();
  } else {
    throw ls_std::FileOperationException{};
  }
}

bool ls_std::File::exists()
{
  return ls_std::File::_exists(this->absoluteFilePath);
}

std::string ls_std::File::getAbsoluteFilePath() {
  return this->absoluteFilePath;
}

std::string ls_std::File::getName()
{
  std::string copy = this->absoluteFilePath;

  // if it's a directory, remove separator from end, if it does exist

  if(ls_std::File::_isDirectory(this->absoluteFilePath)) {
    copy.erase(std::remove_if(copy.end() - 1, copy.end(), ls_std::FilePathSeparatorMatch()), copy.end());
  }

  // now get the file / directory name

  auto base = std::find_if(copy.rbegin(), copy.rend(), ls_std::FilePathSeparatorMatch()).base();
  return std::string(base, copy.end());
}

std::string ls_std::File::getParent()
{
  return ls_std::File::_getParent(this->absoluteFilePath);
}

long ls_std::File::getSize()
{
  std::streampos fileSize {};

  if(ls_std::File::_exists(this->absoluteFilePath)) {
    std::ifstream fileHandler{this->absoluteFilePath, std::ios::in};
    fileSize = fileHandler.tellg();
    fileHandler.seekg(0, std::ios::end);
    fileSize = fileHandler.tellg() - fileSize;
    fileHandler.close();
  }

  return fileSize;
}

bool ls_std::File::isDirectory()
{
  return ls_std::File::_isDirectory(this->absoluteFilePath);
}

bool ls_std::File::isFile()
{
  return ls_std::File::_isFile(this->absoluteFilePath);
}

time_t ls_std::File::lastModified()
{
  return ls_std::File::_lastModified(this->absoluteFilePath);
}

std::list<std::string> ls_std::File::list()
{
  std::list<std::string> fileList {};

  if(ls_std::File::_isDirectory(this->absoluteFilePath)) {
    fileList = ls_std::File::_list(this->absoluteFilePath);
  }

  return fileList;
}

std::list<std::string> ls_std::File::listFiles()
{
  std::list<std::string> fileList {};

  if(ls_std::File::_isDirectory(this->absoluteFilePath)) {
    fileList = ls_std::File::_listFiles(this->absoluteFilePath);
  }

  return fileList;
}

void ls_std::File::makeDirectory()
{
  if(ls_std::File::_mkdir(this->absoluteFilePath)) {
    throw ls_std::FileOperationException {};
  }
}

void ls_std::File::makeDirectories() {
  std::vector<std::string> subDirectories = ls_std::File::_splitIntoSubDirectoryNames(this->absoluteFilePath);
  const char separator = ls_std::FilePathSeparator::get();
  std::string currentHierarchy {};

  for(const auto& subDirectory : subDirectories) {
    currentHierarchy += subDirectory;

    if(!ls_std::File::_exists(currentHierarchy)) {
      ls_std::File::_mkdir(currentHierarchy);
    }

    currentHierarchy += separator;
  }
}

void ls_std::File::remove()
{
  if(ls_std::File::_isFile(this->absoluteFilePath)) {
    if(std::remove(this->absoluteFilePath.c_str())) {
      throw ls_std::FileOperationException{};
    }
  }

  if(ls_std::File::_isDirectory(this->absoluteFilePath)) {
    if(rmdir(this->absoluteFilePath.c_str())) {
      throw ls_std::FileOperationException{};
    }
  }
}

bool ls_std::File::renameTo(const std::string &_newName)
{
  bool renamed = ls_std::File::_renameTo(this->absoluteFilePath, _newName);

  if(renamed) {
    this->absoluteFilePath = _newName;
  }

  return renamed;
}

#ifdef _WIN32
void ls_std::File::_addToFileListWindows(const std::string& _path, bool _withDirectories, WIN32_FIND_DATA _data, std::list<std::string>& _list)
{
  const char separator = ls_std::FilePathSeparator::get();
  std::string absolutePath = _path + separator + _data.cFileName;

  if(_withDirectories) {
    _list.emplace_back(absolutePath);
  } else {
    if(ls_std::File::_isFile(absolutePath)) {
      _list.emplace_back(absolutePath);
    }
  }
}
#endif

#if defined(unix) || defined(__APPLE__)
void ls_std::File::_addToFileListUnix(const std::string& _path, bool _withDirectories, dirent* directoryEntity, std::list<std::string>& _list)
{
  const char separator = ls_std::FilePathSeparator::get();
  std::string absolutePath = _path + separator + directoryEntity->d_name;

  if(_withDirectories) {
    _list.emplace_back(absolutePath);
  } else {
    if(ls_std::File::_isFile(absolutePath)) {
      _list.emplace_back(absolutePath);
    }
  }
}
#endif

bool ls_std::File::_exists(const std::string& _path)
{
  struct stat _stat {};
  return (stat(_path.c_str(), &_stat) == 0);
}

std::string ls_std::File::_getParent(const std::string &_path)
{
  std::string parent {};
  std::vector<std::string> subDirectoryNames = ls_std::File::_splitIntoSubDirectoryNames(_path);
  const char separator = ls_std::FilePathSeparator::get();
  subDirectoryNames.pop_back();

  for(auto const& subDirectoryName : subDirectoryNames) {
    parent += subDirectoryName + separator;
  }

  return parent;
}

bool ls_std::File::_isDirectory(const std::string& _path)
{
  bool match {};
  struct stat _stat {};

  if(stat(_path.c_str(), &_stat) == 0) {
    match = _stat.st_mode & (unsigned short) S_IFDIR;
  }

  return match;
}

bool ls_std::File::_isExecutable(const std::string &_path)
{
  bool executable {};

  if(ls_std::File::_exists(_path)) {
    struct stat _stat {};

    if(stat(_path.c_str(), &_stat) == 0) {
      executable = (_stat.st_mode & (unsigned short) S_IEXEC) != 0;
    }
  }

  return executable;
}

bool ls_std::File::_isFile(const std::string& _path)
{
  bool match {};
  struct stat _stat {};

  if(stat(_path.c_str(), &_stat) == 0) {
    match = _stat.st_mode & (unsigned short) S_IFREG;
  }

  return match;
}

#ifdef _WIN32
bool ls_std::File::_isReadableWindows(const std::string &_path)
{
  bool readable;
  WIN32_FIND_DATA data {};
  HANDLE handleFind = FindFirstFile(_path.c_str(), &data);

  if(handleFind != INVALID_HANDLE_VALUE) {
    readable = GetFileAttributes(data.cFileName) & (unsigned) FILE_ATTRIBUTE_READONLY;
  } else {
    throw ls_std::FileOperationException {};
  }

  return readable;
}
#endif

time_t ls_std::File::_lastModified(const std::string &_path)
{
  time_t lastModifiedTimeStamp {};
  struct stat _stat {};

  if(stat(_path.c_str(), &_stat) == 0) {
    lastModifiedTimeStamp = _stat.st_mtime;
  }

  return lastModifiedTimeStamp;
}

std::list<std::string> ls_std::File::_list(const std::string &_path)
{
  std::list<std::string> filesInDirectory {};

  #if defined(unix) || defined(__APPLE__)
    filesInDirectory = ls_std::File::_listUnix(_path, true);
  #endif
  #ifdef _WIN32
    filesInDirectory = ls_std::File::_listWindows(_path, true);
  #endif

  return filesInDirectory;
}

std::list<std::string> ls_std::File::_listFiles(const std::string &_path)
{
  std::list<std::string> filesInDirectory {};

  #if defined(unix) || defined(__APPLE__)
    filesInDirectory = ls_std::File::_listUnix(_path, false);
  #endif
  #ifdef _WIN32
    filesInDirectory = ls_std::File::_listWindows(_path, false);
  #endif

  return filesInDirectory;
}

#if defined(unix) || defined(__APPLE__)
std::list<std::string> ls_std::File::_listUnix(const std::string &_path, bool withDirectories)
{
  std::list<std::string> filesInDirectory {};
  DIR* directory = opendir(_path.c_str());
  struct dirent* directoryEntity;
  std::string absolutePath {};

  while((directoryEntity = readdir(directory)) != nullptr) {
    ls_std::File::_addToFileListUnix(_path, withDirectories, directoryEntity, filesInDirectory);
  }

  return filesInDirectory;
}
#endif

#ifdef _WIN32
std::list<std::string> ls_std::File::_listWindows(const std::string &_path, bool withDirectories)
{
  std::list<std::string> filesInDirectory {};
  WIN32_FIND_DATA data {};
  HANDLE hFind;
  std::string pattern {_path + ls_std::FilePathSeparator::get() + "*"};

  if((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
    do {
      ls_std::File::_addToFileListWindows(_path, withDirectories, data, filesInDirectory);
    }
    while(FindNextFile(hFind, &data) != 0);

    FindClose(hFind);
  }

  return filesInDirectory;
}
#endif

int ls_std::File::_mkdir(const std::string& _path) {
  int result;

  #ifdef _WIN32
    result = mkdir(_path.c_str());
  #endif

  #if defined(unix) || defined(__APPLE__)
    result = mkdir(_path.c_str(), 0777);
  #endif

  return result;
}

std::string ls_std::File::_normalizePath(std::string _path)
{
  _path = ls_std::File::_replaceWrongSeparator(_path);
  _path = ls_std::File::_reduceSeparators(_path);

  return _path;
}

std::string ls_std::File::_reduceSeparators(const std::string& _path)
{
  static const char separator = {ls_std::FilePathSeparator::get()};
  std::string normalizedPath {};
  int index {};

  while(index  < _path.size()) {
    if(_path[index] == separator) {
      normalizedPath += _path[index];

      do {
        index++;
      }
      while(_path[index] == separator);
    } else {
      normalizedPath += _path[index];
      index++;
    }
  }

  return normalizedPath;
}

bool ls_std::File::_renameTo(const std::string &_oldName, const std::string &_newName)
{
  return std::rename(_oldName.c_str(), _newName.c_str()) == 0;
}

std::string ls_std::File::_replaceWrongSeparator(std::string _path)
{
  static const char unixSeparator = ls_std::FilePathSeparator::getUnixFilePathSeparator();
  static const char windowsSeparator = ls_std::FilePathSeparator::getWindowsFilePathSeparator();

  #if defined(unix) || defined(__APPLE__)
    std::replace(_path.begin(), _path.end(), windowsSeparator, unixSeparator);
  #endif

  #ifdef _WIN32
    std::replace(_path.begin(), _path.end(), unixSeparator, windowsSeparator);
  #endif

  return _path;
}

std::vector<std::string> ls_std::File::_splitIntoSubDirectoryNames(const std::string& _path) {
  std::vector<std::string> subDirectoryNames {};
  std::stringstream _stream {_path};
  std::string subDirectoryName {};
  const char separator = ls_std::FilePathSeparator::get();

  while(std::getline(_stream, subDirectoryName, separator)) {
    subDirectoryNames.push_back(subDirectoryName);
  }

  return subDirectoryNames;
}
