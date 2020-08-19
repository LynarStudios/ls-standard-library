/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-16
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
      std::string location {};

      #ifdef _WIN32
        location = TestHelper::getTestFolderLocation() + R"(resources\)";
      #endif
      #ifdef unix
        location = TestHelper::getTestFolderLocation() + R"(resources/)";
      #endif
      #ifdef __APPLE__
        location = TestHelper::getTestFolderLocation() + R"(resources/)";
      #endif

      return location;
    }

    static std::string getTestFolderLocation() {
      std::string location {};

      #ifdef _WIN32
        location = R"(C:\Users\drums\CLionProjects\lynar-studios-standard-library\test\)";
      #endif
      #ifdef unix
        location = R"(/home/patrick/CLionProjects/lynar-studios-standard-library/test/)";
      #endif
      #ifdef __APPLE__
        location = R"(/Users/patrickmattulat/CLionProjects/lynar-studios-standard-library/test/)";
      #endif

      return location;
    }
};

#endif
