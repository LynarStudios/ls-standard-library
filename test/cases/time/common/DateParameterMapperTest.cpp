/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-31
* Changed:         2023-04-01
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-time.hpp>
#include <utility>
#include <vector>
#ifdef _WIN32
  #include <windows.h>
#endif

using ls::std::time::DateParameter;
using ls::std::time::DateParameterMapper;
using ls::std::time::type::UnixTimestamp;
using std::pair;
using std::vector;
using testing::TestWithParam;
using testing::Values;

namespace
{
#if defined(unix) || defined(__APPLE__)
  class DateParameterMapperTest_Unix : public TestWithParam<pair<UnixTimestamp, DateParameter>>
  {
    public:

      DateParameterMapperTest_Unix() = default;
      ~DateParameterMapperTest_Unix() override = default;

      static vector<pair<UnixTimestamp, DateParameter>> getTestParameterList()
      {
        vector<pair<UnixTimestamp, DateParameter>> testParameterList{};
        testParameterList.emplace_back(656936700, DateParameter{1990, 10, 26, 11, 25, 00});
        testParameterList.emplace_back(612694320, DateParameter{1989, 6, 1, 10, 52, 00});

        return testParameterList;
      }
  };

  TEST_P(DateParameterMapperTest_Unix, toUnixTimestamp)
  {
    DateParameter dateParameter = GetParam().second;
    UnixTimestamp timestamp = DateParameterMapper::toUnixTimestamp(dateParameter);

    ASSERT_EQ(GetParam().first, timestamp);
  }

  INSTANTIATE_TEST_SUITE_P(toUnixTimestamp, DateParameterMapperTest_Unix, Values(DateParameterMapperTest_Unix::getTestParameterList().at(0), DateParameterMapperTest_Unix::getTestParameterList().at(1)));
#endif
#ifdef _WIN32
  class DateParameterMapperTest_Windows : public TestWithParam<DateParameter>
  {
    public:

      DateParameterMapperTest_Windows() = default;
      ~DateParameterMapperTest_Windows() override = default;

      static vector<DateParameter> getTestParameterList()
      {
        vector<DateParameter> testParameterList{};
        testParameterList.emplace_back(1990, 10, 26, 11, 25, 00);
        testParameterList.emplace_back(1989, 6, 1, 10, 52, 00);

        return testParameterList;
      }
  };

  TEST_P(DateParameterMapperTest_Windows, toWindowsSystemTime)
  {
    DateParameter dateParameter = GetParam();
    SYSTEMTIME systemTime = DateParameterMapper::toWindowsSystemTime(dateParameter);

    ASSERT_EQ(systemTime.wYear, GetParam().getYear());
    ASSERT_EQ(systemTime.wMonth, GetParam().getMonth());
    ASSERT_EQ(systemTime.wDayOfWeek, 0);
    ASSERT_EQ(systemTime.wDay, GetParam().getDay());
    ASSERT_EQ(systemTime.wHour, GetParam().getHour());
    ASSERT_EQ(systemTime.wMinute, GetParam().getMinute());
    ASSERT_EQ(systemTime.wSecond, GetParam().getSecond());
    ASSERT_EQ(systemTime.wMilliseconds, 0);
  }

  INSTANTIATE_TEST_SUITE_P(toWindowsSystemTime, DateParameterMapperTest_Windows, Values(DateParameterMapperTest_Windows::getTestParameterList().at(0), DateParameterMapperTest_Windows::getTestParameterList().at(1)));
#endif
}
