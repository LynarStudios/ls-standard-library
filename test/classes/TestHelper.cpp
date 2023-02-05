/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <algorithm>
#include <classes/TestHelper.hpp>
#include <climits>
#include <fstream>
#include <ls-std/core/types/Types.hpp>
#include <sstream>
#include <stdexcept>
#include <string>
#if defined(unix) || defined(__APPLE__)
  #include <unistd.h>
#endif
#ifdef _WIN32
  #include <windows.h>
#endif

ls::std::test::TestHelper::TestHelper() = default;

ls::std::test::TestHelper::~TestHelper() = default;

::std::string ls::std::test::TestHelper::getResourcesFolderLocation()
{
  return TestHelper::getTestFolderLocation() + "resources" + ls::std::test::TestHelper::_getFilePathSeparator();
}

::std::string ls::std::test::TestHelper::getTestFolderLocation()
{
  ::std::string buildDirectory = ls::std::test::TestHelper::_getWorkingDirectory();
  buildDirectory = ls::std::test::TestHelper::_normalizePath(buildDirectory);

  return ls::std::test::TestHelper::_getParent(buildDirectory) + "test" + ls::std::test::TestHelper::_getFilePathSeparator();
}

::std::string ls::std::test::TestHelper::normalize(const ::std::string &_path)
{
  return ls::std::test::TestHelper::_normalizePath(_path);
}

char ls::std::test::TestHelper::_getFilePathSeparator()
{
  char separator;

#ifdef _WIN32
  separator = '\\';
#endif
#if defined(unix) || defined(__APPLE__)
  separator = '/';
#endif

  return separator;
}

::std::string ls::std::test::TestHelper::_getParent(const ::std::string &_path)
{
  ::std::string parent{};
  ::std::vector<::std::string> subDirectoryNames = ls::std::test::TestHelper::_splitIntoSubDirectoryNames(_path);
  const char separator = ls::std::test::TestHelper::_getFilePathSeparator();
  subDirectoryNames.pop_back();

  for (auto const &subDirectoryName : subDirectoryNames)
  {
    parent += subDirectoryName + separator;
  }

  return parent;
}

::std::string ls::std::test::TestHelper::_getWorkingDirectory()
{
  ::std::string workingDirectory{};

#if defined(unix) || defined(__APPLE__)
  workingDirectory = ls::std::test::TestHelper::_getWorkingDirectoryUnix();
#endif
#ifdef _WIN32
  workingDirectory = ls::std::test::TestHelper::_getWorkingDirectoryWindows();
#endif

  return workingDirectory;
}

#if defined(unix) || defined(__APPLE__)
::std::string ls::std::test::TestHelper::_getWorkingDirectoryUnix()
{
  ::std::string workingDirectory{};
  char buffer[PATH_MAX];

  if (getcwd(buffer, sizeof(buffer)) == nullptr)
  {
    throw ::std::runtime_error{"invalid file operation!"};
  }
  else
  {
    workingDirectory = ::std::string(buffer);
  }

  return workingDirectory;
}
#endif

#ifdef _WIN32
static ::std::string _getWorkingDirectoryWindows()
{
  ::std::string workingDirectory{};
  TCHAR buffer[MAX_PATH];

  if (!GetCurrentDirectory(MAX_PATH, buffer))
  {
    throw ::std::runtime_error{"invalid file operation!"};
  }
  else
  {
    workingDirectory = ::std::string(buffer);
  }

  return workingDirectory;
}
#endif

::std::string ls::std::test::TestHelper::_normalizePath(::std::string _path)
{
  _path = ls::std::test::TestHelper::_replaceWrongSeparator(_path);
  _path = ls::std::test::TestHelper::_reduceSeparators(_path);

  return _path;
}

::std::string ls::std::test::TestHelper::_reduceSeparators(const ::std::string &_path)
{
  static const char separator = {ls::std::test::TestHelper::_getFilePathSeparator()};
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

::std::string ls::std::test::TestHelper::_replaceWrongSeparator(::std::string _path)
{
  static const char unixSeparator = '/';
  static const char windowsSeparator = '\\';

#if defined(unix) || defined(__APPLE__)
  ::std::replace(_path.begin(), _path.end(), windowsSeparator, unixSeparator);
#endif

#ifdef _WIN32
  ::std::replace(_path.begin(), _path.end(), unixSeparator, windowsSeparator);
#endif

  return _path;
}

::std::vector<::std::string> ls::std::test::TestHelper::_splitIntoSubDirectoryNames(const ::std::string &_path)
{
  ::std::vector<::std::string> subDirectoryNames{};
  ::std::stringstream _stream{_path};
  ::std::string subDirectoryName{};
  const char separator = ls::std::test::TestHelper::_getFilePathSeparator();

  while (::std::getline(_stream, subDirectoryName, separator))
  {
    subDirectoryNames.push_back(subDirectoryName);
  }

  return subDirectoryNames;
}
