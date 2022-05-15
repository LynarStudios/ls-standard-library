/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-14
 *
 * */

#ifndef LS_STD_IO_TEST_HELPER_HPP
#define LS_STD_IO_TEST_HELPER_HPP

#include <string>
#include <ls_std/ls_std_io.hpp>

namespace ls_std_io_test
{
  class TestHelper
  {
    public:

      TestHelper() = default;
      ~TestHelper() = default;

      static std::string getResourcesFolderLocation()
      {
        return TestHelper::getTestFolderLocation() + "resources" + ls::std::io::FilePathSeparator::get();
      }

      static std::string getTestFolderLocation()
      {
        ls::std::io::File buildDirectory{ls::std::io::File::getWorkingDirectory()};
        return buildDirectory.getParent() + "test" + ls::std::io::FilePathSeparator::get();
      }
  };
}

#endif
