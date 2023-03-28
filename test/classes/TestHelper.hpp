/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-03-27
 *
 * */

#ifndef LS_STD_IO_TEST_HELPER_HPP
#define LS_STD_IO_TEST_HELPER_HPP

#include <string>
#include <vector>

namespace ls::std::test
{
  class TestHelper
  {
    public:

      TestHelper();
      ~TestHelper();

      [[nodiscard]] static ::std::string getResourcesFolderLocation();
      [[nodiscard]] static ::std::string getTestFolderLocation();

    private:

      [[nodiscard]] static char _getFilePathSeparator();
      [[nodiscard]] static ::std::string _getParent(const ::std::string &_path);
      [[nodiscard]] static ::std::string _getWorkingDirectory();

#if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static ::std::string _getWorkingDirectoryUnix();
#endif
#ifdef _WIN32
      [[nodiscard]] static ::std::string _getWorkingDirectoryWindows();
#endif

      [[nodiscard]] static ::std::string _normalizePath(::std::string _path);
      [[nodiscard]] static ::std::string _reduceSeparators(const ::std::string &_path);
      [[nodiscard]] static ::std::string _replaceWrongSeparator(::std::string _path);
      [[nodiscard]] static ::std::vector<::std::string> _splitIntoSubDirectoryNames(const ::std::string &_path);
  };
}

#endif
