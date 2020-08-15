/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-15
 *
 * */

#ifndef TEST_HELPER_HPP
#define TEST_HELPER_HPP

#include <string>

class TestHelper {
  public:

    TestHelper() = default;
    ~TestHelper() = default;

    static std::string getResourcesFolderLocation() {
      return TestHelper::getTestFolderLocation() + R"(resources\)";
    }

    static std::string getTestFolderLocation() {
      return R"(C:\Users\drums\CLionProjects\lynar-studios-standard-library\test\)";
    }
};

#endif
