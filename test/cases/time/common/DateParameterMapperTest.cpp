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
}
