/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-29
* Changed:         2023-03-29
*
* */

#ifndef LS_STD_DATE_PARAMETER_HPP
#define LS_STD_DATE_PARAMETER_HPP

#include <cstdint>
#include <ls-std/os/dynamic-goal.hpp>
#include <ls-std/time/type/DateParameterTypes.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL DateParameter
  {
    public:

      DateParameter(ls::std::time::type::Year _year, ls::std::time::type::Month _month, ls::std::time::type::Day _day, ls::std::time::type::Hour _hour, ls::std::time::type::Minute _minute, ls::std::time::type::Second _second, ls::std::time::type::Millisecond _millisecond);
      DateParameter();
      ~DateParameter();

      [[nodiscard]] ls::std::time::type::Day getDay() const;
      [[nodiscard]] ls::std::time::type::Hour getHour() const;
      [[nodiscard]] ls::std::time::type::Millisecond getMillisecond() const;
      [[nodiscard]] ls::std::time::type::Minute getMinute() const;
      [[nodiscard]] ls::std::time::type::Month getMonth() const;
      [[nodiscard]] ls::std::time::type::Second getSecond() const;
      [[nodiscard]] ls::std::time::type::Year getYear() const;
      void setDay(ls::std::time::type::Day _day);
      void setHour(ls::std::time::type::Hour _hour);
      void setMillisecond(ls::std::time::type::Millisecond _millisecond);
      void setMinute(ls::std::time::type::Minute _minute);
      void setMonth(ls::std::time::type::Month _month);
      void setSecond(ls::std::time::type::Second _second);
      void setYear(ls::std::time::type::Year _year);

    private:

      ls::std::time::type::Day day{};
      ls::std::time::type::Hour hour{};
      ls::std::time::type::Millisecond millisecond{};
      ls::std::time::type::Minute minute{};
      ls::std::time::type::Month month{};
      ls::std::time::type::Second second{};
      ls::std::time::type::Year year{};
  };
}

#endif
