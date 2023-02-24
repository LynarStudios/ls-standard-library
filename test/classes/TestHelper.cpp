/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-23
*
* */

#include <algorithm>
#include <classes/TestHelper.hpp>
#include <climits>
#include <fstream>
#include <ls-std/core/type/Types.hpp>
#include <sstream>
#include <stdexcept>
#include <string>
#if defined(unix) || defined(__APPLE__)
  #include <unistd.h>
#endif
#ifdef _WIN32
  #include <windows.h>
#endif

using ls::std::test::TestHelper;
using std::getline;
using std::replace;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::vector;

TestHelper::TestHelper() = default;

TestHelper::~TestHelper() = default;

string TestHelper::getResourcesFolderLocation()
{
  return TestHelper::getTestFolderLocation() + "resources" + TestHelper::_getFilePathSeparator();
}

string TestHelper::getTestFolderLocation()
{
  string buildDirectory = TestHelper::_getWorkingDirectory();
  buildDirectory = TestHelper::_normalizePath(buildDirectory);

  return TestHelper::_getParent(buildDirectory) + "test" + TestHelper::_getFilePathSeparator();
}

char TestHelper::_getFilePathSeparator()
{
#ifdef _WIN32
  return '\\';
#endif
#if defined(unix) || defined(__APPLE__)
  return '/';
#endif
}

string TestHelper::_getParent(const string &_path)
{
  string parent{};
  vector<string> subDirectoryNames = TestHelper::_splitIntoSubDirectoryNames(_path);
  const char separator = TestHelper::_getFilePathSeparator();
  subDirectoryNames.pop_back();

  for (auto const &subDirectoryName : subDirectoryNames)
  {
    parent += subDirectoryName + separator;
  }

  return parent;
}

string TestHelper::_getWorkingDirectory()
{
  string workingDirectory{};

#if defined(unix) || defined(__APPLE__)
  workingDirectory = TestHelper::_getWorkingDirectoryUnix();
#endif
#ifdef _WIN32
  workingDirectory = TestHelper::_getWorkingDirectoryWindows();
#endif

  return workingDirectory;
}

#if defined(unix) || defined(__APPLE__)
string TestHelper::_getWorkingDirectoryUnix()
{
  string workingDirectory{};
  char buffer[PATH_MAX];

  if (getcwd(buffer, sizeof(buffer)) == nullptr)
  {
    throw runtime_error{"invalid file operation!"};
  }
  else
  {
    workingDirectory = string(buffer);
  }

  return workingDirectory;
}
#endif

#ifdef _WIN32
string TestHelper::_getWorkingDirectoryWindows()
{
  string workingDirectory{};
  TCHAR buffer[MAX_PATH];

  if (!GetCurrentDirectory(MAX_PATH, buffer))
  {
    throw runtime_error{"invalid file operation!"};
  }
  else
  {
    workingDirectory = string(buffer);
  }

  return workingDirectory;
}
#endif

string TestHelper::_normalizePath(string _path)
{
  _path = TestHelper::_replaceWrongSeparator(_path);
  _path = TestHelper::_reduceSeparators(_path);

  return _path;
}

string TestHelper::_reduceSeparators(const string &_path)
{
  static const char separator = {TestHelper::_getFilePathSeparator()};
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

string TestHelper::_replaceWrongSeparator(string _path)
{
  static const char unixSeparator = '/';
  static const char windowsSeparator = '\\';

#if defined(unix) || defined(__APPLE__)
  replace(_path.begin(), _path.end(), windowsSeparator, unixSeparator);
#endif

#ifdef _WIN32
  replace(_path.begin(), _path.end(), unixSeparator, windowsSeparator);
#endif

  return _path;
}

vector<string> TestHelper::_splitIntoSubDirectoryNames(const string &_path)
{
  vector<string> subDirectoryNames{};
  stringstream _stream{_path};
  string subDirectoryName{};
  const char separator = TestHelper::_getFilePathSeparator();

  while (getline(_stream, subDirectoryName, separator))
  {
    subDirectoryNames.push_back(subDirectoryName);
  }

  return subDirectoryNames;
}
