/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2022-05-05
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
      return TestHelper::getTestFolderLocation() + "resources" + ls::FilePathSeparator::get();
    }

    static std::string getTestFolderLocation()
    {
      ls::File buildDirectory{ls::File::getWorkingDirectory()};
      return buildDirectory.getParent() + "test" + ls::FilePathSeparator::get();
    }
};

#endif
