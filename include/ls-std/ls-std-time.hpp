/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-16
 * Changed:         2023-04-01
 *
 * */

#ifndef LS_STD_LS_STD_TIME_HPP
#define LS_STD_LS_STD_TIME_HPP

#include <ls-std/time/common/DateParameter.hpp>
#include <ls-std/time/common/DateParameterMapper.hpp>

#include <ls-std/time/system-time/IClock.hpp>
#if defined(unix) || defined(__APPLE__)
  #include <ls-std/time/system-time/PosixClock.hpp>
#endif
#include <ls-std/time/system-time/SystemTime.hpp>
#include <ls-std/time/system-time/SystemTimeParameter.hpp>
#ifdef _WIN32
  #include <ls-std/time/system-time/WindowsClock.hpp>
#endif

#include <ls-std/time/type/DateParameterTypes.hpp>

#include <ls-std/time/Date.hpp>

#endif
