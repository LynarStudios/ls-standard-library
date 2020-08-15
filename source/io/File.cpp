/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-15
 *
 * */

#include "File.hpp"
#include "../exception/FileOperationException.hpp"
#include "FilePathSeparatorMatch.hpp"
#include <fstream>
#include <sys/stat.h>
#include <algorithm>

#ifdef unix
#include <unistd.h>
#include <vector>
#include <sstream>

#endif

ls_std::File::File(std::string _absoluteFilePath) : Class("File"),
absoluteFilePath(ls_std::File::_normalizePath(std::move(_absoluteFilePath)))
{}

bool ls_std::File::operator==(File &_file)
{
  return this->absoluteFilePath == _file.getAbsoluteFilePath();
}

bool ls_std::File::operator!=(File &_file)
{
  return this->absoluteFilePath != _file.getAbsoluteFilePath();
}

bool ls_std::File::canExecute()
{
  bool executable {};
  struct stat _stat {};

  if(stat(this->absoluteFilePath.c_str(), &_stat) == 0) {
    executable = (_stat.st_mode & (unsigned short) S_IEXEC) != 0;
  }

  return executable;
}

void ls_std::File::create()
{
  if(!this->_exists(this->absoluteFilePath)) {
    std::ofstream file {this->absoluteFilePath};
    file.close();
  } else {
    throw ls_std::FileOperationException{this->absoluteFilePath};
  }
}

bool ls_std::File::exists()
{
  return this->_exists(this->absoluteFilePath);
}

std::string ls_std::File::getAbsoluteFilePath() {
  return this->absoluteFilePath;
}

std::string ls_std::File::getName()
{
  std::string copy = this->absoluteFilePath;

  // if it's a directory, remove separator from end, if it does exist

  if(this->_isDirectory(this->absoluteFilePath)) {
    copy.erase(std::remove_if(copy.end() - 1, copy.end(), ls_std::FilePathSeparatorMatch()), copy.end());
  }

  // now get the file / directory name

  auto base = std::find_if(copy.rbegin(), copy.rend(), ls_std::FilePathSeparatorMatch()).base();
  return std::string(base, copy.end());
}

long ls_std::File::getSize()
{
  std::streampos fileSize {};

  if(this->_exists(this->absoluteFilePath)) {
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
  return this->_isDirectory(this->absoluteFilePath);
}

bool ls_std::File::isFile()
{
  return this->_isFile(this->absoluteFilePath);
}

void ls_std::File::makeDirectory()
{
  if(ls_std::File::_mkdir(this->absoluteFilePath)) {
    throw ls_std::FileOperationException {this->absoluteFilePath};
  }
}

void ls_std::File::makeDirectories() {
  std::vector<std::string> subDirectories = ls_std::File::_splitIntoSubDirectoryNames(this->absoluteFilePath);
  const char separator = ls_std::FilePathSeparator::getOperatingSystemSpecificSeparator();
  std::string currentHierarchy {};

  for(const auto& subDirectory : subDirectories) {
    currentHierarchy += subDirectory;

    if(!this->_exists(currentHierarchy)) {
      ls_std::File::_mkdir(currentHierarchy);
    }

    currentHierarchy += separator;
  }
}

void ls_std::File::remove()
{
  if(this->_isFile(this->absoluteFilePath)) {
    if(std::remove(this->absoluteFilePath.c_str())) {
      throw ls_std::FileOperationException{this->absoluteFilePath};
    }
  }

  if(this->_isDirectory(this->absoluteFilePath)) {
    if(rmdir(this->absoluteFilePath.c_str())) {
      throw ls_std::FileOperationException{this->absoluteFilePath};
    }
  }
}

bool ls_std::File::_exists(const std::string& path)
{
  struct stat _stat {};
  return (stat(this->absoluteFilePath.c_str(), &_stat) == 0);
}

bool ls_std::File::_isDirectory(const std::string& path)
{
  bool match {};
  struct stat _stat {};

  if(stat(this->absoluteFilePath.c_str(), &_stat) == 0) {
    match = _stat.st_mode & (unsigned short) S_IFDIR;
  }

  return match;
}

bool ls_std::File::_isFile(const std::string& path)
{
  bool match {};
  struct stat _stat {};

  if(stat(this->absoluteFilePath.c_str(), &_stat) == 0) {
    match = _stat.st_mode & (unsigned short) S_IFREG;
  }

  return match;
}

int ls_std::File::_mkdir(const std::string& path) {
  int result {};

  #ifdef _WIN32
    result = mkdir(path.c_str());
  #endif

  #ifdef unix
    result = mkdir(path.c_str(), 0777);
  #endif

  return result;
}

std::string ls_std::File::_normalizePath(std::string path)
{
  #ifdef unix
    std::replace(path.begin(), path.end(), '\\', '/');
  #endif

  #ifdef _WIN32
    std::replace(path.begin(), path.end(), '/', '\\');
  #endif

  return path;
}

std::vector<std::string> ls_std::File::_splitIntoSubDirectoryNames(const std::string& path) {
  std::vector<std::string> subDirectoryNames {};
  std::stringstream _stream {path};
  std::string subDirectoryName {};
  const char separator = ls_std::FilePathSeparator::getOperatingSystemSpecificSeparator();

  while(std::getline(_stream, subDirectoryName, separator)) {
    subDirectoryNames.push_back(subDirectoryName);
  }

  return subDirectoryNames;
}
