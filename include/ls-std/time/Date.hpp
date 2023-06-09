/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_DATE_HPP
#define LS_STD_DATE_HPP

#include <ctime>
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::time
{
  class LS_STD_DYNAMIC_GOAL Date : public ls::std::core::Class
  {
    public:

      Date();
      ~Date() noexcept override;

      // arithmetic operators

      ls::std::time::Date &operator+(int _value);
      ls::std::time::Date &operator-(int _value);
      ls::std::time::Date &operator+=(int _value);
      ls::std::time::Date &operator-=(int _value);

      // additional functionality

      [[nodiscard]] bool after(const ls::std::time::Date &_foreignDate) const;
      [[nodiscard]] bool before(const ls::std::time::Date &_foreignDate) const;
      [[nodiscard]] int getDay();
      [[nodiscard]] int getHour();
      [[nodiscard]] int getMinute();
      [[nodiscard]] int getMonth();
      [[nodiscard]] int getSecond();
      [[nodiscard]] time_t getTime() const;
      [[nodiscard]] int getYear();
      void setTime(time_t _timestamp);
      [[nodiscard]] ::std::string toString();

    private:

      time_t timestamp{};
      tm *localTime{};

      void _decrementByDays(int _value);
      void _incrementByDays(int _value);
      void _init();
  };
}

#endif
