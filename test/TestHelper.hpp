/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-15
 *
 * */

#ifndef LS_STD_IO_TEST_HELPER_HPP
#define LS_STD_IO_TEST_HELPER_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <climits>
#include <unistd.h>

namespace ls_std_test
{
  class TestHelper
  {
    public:

      TestHelper() = default;
      ~TestHelper() = default;

      static std::string getResourcesFolderLocation()
      {
        return TestHelper::getTestFolderLocation() + "resources" + ls_std_test::TestHelper::_getFilePathSeparator();
      }

      static std::string getTestFolderLocation()
      {
        ::std::string buildDirectory = ls_std_test::TestHelper::_getWorkingDirectory();
        buildDirectory = ls_std_test::TestHelper::_normalizePath(buildDirectory);

        return ls_std_test::TestHelper::_getParent(buildDirectory) + "test" + ls_std_test::TestHelper::_getFilePathSeparator();
      }

    private:

      static char _getFilePathSeparator()
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

      static std::string _getParent(const ::std::string &_path)
      {
        ::std::string parent{};
        ::std::vector<::std::string> subDirectoryNames = ls_std_test::TestHelper::_splitIntoSubDirectoryNames(_path);
        const char separator = ls_std_test::TestHelper::_getFilePathSeparator();
        subDirectoryNames.pop_back();

        for (auto const &subDirectoryName: subDirectoryNames)
        {
          parent += subDirectoryName + separator;
        }

        return parent;
      }

      static ::std::string _getWorkingDirectory()
      {
        ::std::string workingDirectory{};

        #if defined(unix) || defined(__APPLE__)
        workingDirectory = ls_std_test::TestHelper::_getWorkingDirectoryUnix();
        #endif
        #ifdef _WIN32
        workingDirectory = ls_std_test::TestHelper::_getWorkingDirectoryWindows();
        #endif

        return workingDirectory;
      }

      #if defined(unix) || defined(__APPLE__)

      static ::std::string _getWorkingDirectoryUnix()
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

      ::std::string _getWorkingDirectoryWindows()
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

      static ::std::string _normalizePath(::std::string _path)
      {
        _path = ls_std_test::TestHelper::_replaceWrongSeparator(_path);
        _path = ls_std_test::TestHelper::_reduceSeparators(_path);

        return _path;
      }

      static ::std::string _reduceSeparators(const ::std::string &_path)
      {
        static const char separator = {ls_std_test::TestHelper::_getFilePathSeparator()};
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

      static ::std::string _replaceWrongSeparator(::std::string _path)
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

      static ::std::vector<::std::string> _splitIntoSubDirectoryNames(const ::std::string &_path)
      {
        ::std::vector<::std::string> subDirectoryNames{};
        ::std::stringstream _stream{_path};
        ::std::string subDirectoryName{};
        const char separator = ls_std_test::TestHelper::_getFilePathSeparator();

        while (::std::getline(_stream, subDirectoryName, separator))
        {
          subDirectoryNames.push_back(subDirectoryName);
        }

        return subDirectoryNames;
      }
  };
}

#endif
