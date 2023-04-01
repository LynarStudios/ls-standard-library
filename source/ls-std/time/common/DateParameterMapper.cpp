/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-31
* Changed:         2023-04-01
*
* */

#if defined(unix) || defined(__APPLE__)
  #include <ctime>
#endif
#include <ls-std/time/common/DateParameterMapper.hpp>

using ls::std::time::DateParameter;
using ls::std::time::DateParameterMapper;
using ls::std::time::type::UnixTimestamp;

DateParameterMapper::DateParameterMapper() = default;

DateParameterMapper::~DateParameterMapper() = default;

#if defined(unix) || defined(__APPLE__)
UnixTimestamp DateParameterMapper::toUnixTimestamp(const DateParameter &_dateParameter)
{
  time_t rawTime{};
  ::time(&rawTime);
  tm *timeInfo = localtime(&rawTime);
  timeInfo->tm_year = _dateParameter.getYear() - 1900;
  timeInfo->tm_mon = _dateParameter.getMonth() - 1;
  timeInfo->tm_mday = _dateParameter.getDay();
  timeInfo->tm_hour = _dateParameter.getHour();
  timeInfo->tm_min = _dateParameter.getMinute();
  timeInfo->tm_sec = _dateParameter.getSecond();
  timeInfo->tm_isdst = -1;

  return (UnixTimestamp) mktime(timeInfo);
}
#endif
