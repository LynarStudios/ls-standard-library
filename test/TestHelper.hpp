/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2021-09-26
 *
 * */

#ifndef TEST_HELPER_HPP
#define TEST_HELPER_HPP

#include <string>
#include <ls_std/ls_std.hpp>

class TestHelper
{
  public:

    TestHelper() = default;
    ~TestHelper() = default;

    static std::string getResourcesFolderLocation()
    {
      return TestHelper::getTestFolderLocation() + "resources" + ls_std::FilePathSeparator::get();
    }

    static std::string getTestFolderLocation()
    {
      ls_std::File buildDirectory{ls_std::File::getWorkingDirectory()};
      return buildDirectory.getParent() + "test" + ls_std::FilePathSeparator::get();
    }
};

#endif
