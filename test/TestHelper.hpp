/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_IO_TEST_HELPER_HPP
#define LS_STD_IO_TEST_HELPER_HPP

#include <algorithm>
#include <climits>
#include <fstream>
#include <ls-std/core/types/Types.hpp>
#include <sstream>
#include <stdexcept>
#include <string>
#if defined(unix) || defined(__APPLE__)
  #include <sys/stat.h>
  #include <unistd.h>
#endif
#include <vector>
#ifdef _WIN32
  #include <windows.h>
#endif

namespace ls::std::test
{
  class TestHelper // TODO: create source file & move to "classes" location
  {
    public:

      TestHelper() = default;
      ~TestHelper() = default;

      static ::std::string getResourcesFolderLocation()
      {
        return TestHelper::getTestFolderLocation() + "resources" + ls::std::test::TestHelper::_getFilePathSeparator();
      }

      static ::std::string getTestFolderLocation()
      {
        ::std::string buildDirectory = ls::std::test::TestHelper::_getWorkingDirectory();
        buildDirectory = ls::std::test::TestHelper::_normalizePath(buildDirectory);

        return ls::std::test::TestHelper::_getParent(buildDirectory) + "test" + ls::std::test::TestHelper::_getFilePathSeparator();
      }

      static ::std::string normalize(const ::std::string &_path)
      {
        return ls::std::test::TestHelper::_normalizePath(_path);
      }

      static ::std::string readFile(const ::std::string &_absoluteFilePath)
      {
        char *data;
        ::std::ifstream inputStream{_absoluteFilePath, ::std::ifstream::binary};
        int length = (int) ls::std::test::TestHelper::_getFileSize(_absoluteFilePath);
        data = new ls::std::core::type::byte[length];
        inputStream.read(data, length);

        if (inputStream.fail())
        {
          throw ::std::runtime_error("invalid file operation!");
        }

        inputStream.close();
        ls::std::core::type::byte_field readData = ls::std::core::type::byte_field{data, (size_t) ls::std::test::TestHelper::_getFileSize(_absoluteFilePath)};
        delete[] data;

        return readData;
      }

    private:

      static bool _fileExists(const ::std::string &_path)
      {
        struct stat _stat
        {
        };
        return (stat(_path.c_str(), &_stat) == 0);
      }

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

      static long _getFileSize(const ::std::string &_absoluteFilePath)
      {
        ::std::streampos fileSize{};

        if (ls::std::test::TestHelper::_fileExists(_absoluteFilePath))
        {
          ::std::ifstream fileHandler{_absoluteFilePath, ::std::ios::in};
          fileSize = fileHandler.tellg();
          fileHandler.seekg(0, ::std::ios::end);
          fileSize = fileHandler.tellg() - fileSize;
          fileHandler.close();
        }

        return (long) fileSize;
      }

      static ::std::string _getParent(const ::std::string &_path)
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

      static ::std::string _getWorkingDirectory()
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

      static ::std::string _normalizePath(::std::string _path)
      {
        _path = ls::std::test::TestHelper::_replaceWrongSeparator(_path);
        _path = ls::std::test::TestHelper::_reduceSeparators(_path);

        return _path;
      }

      static ::std::string _reduceSeparators(const ::std::string &_path)
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
        const char separator = ls::std::test::TestHelper::_getFilePathSeparator();

        while (::std::getline(_stream, subDirectoryName, separator))
        {
          subDirectoryNames.push_back(subDirectoryName);
        }

        return subDirectoryNames;
      }
  };
}

#endif
