/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-05
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

      static ::std::string getResourcesFolderLocation();
      static ::std::string getTestFolderLocation();
      static ::std::string normalize(const ::std::string &_path);

    private:

      static char _getFilePathSeparator();
      static ::std::string _getParent(const ::std::string &_path);
      static ::std::string _getWorkingDirectory();

#if defined(unix) || defined(__APPLE__)
      static ::std::string _getWorkingDirectoryUnix();
#endif
#ifdef _WIN32
      static ::std::string _getWorkingDirectoryWindows();
#endif

      static ::std::string _normalizePath(::std::string _path);
      static ::std::string _reduceSeparators(const ::std::string &_path);
      static ::std::string _replaceWrongSeparator(::std::string _path);
      static ::std::vector<::std::string> _splitIntoSubDirectoryNames(const ::std::string &_path);
  };
}

#endif
