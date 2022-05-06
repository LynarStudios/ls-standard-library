/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_DATE_HPP
#define LS_STD_DATE_HPP

#include <ls_std/core/Class.hpp>
#include <ctime>

namespace ls
{
  class Date : public ls::Class
  {
    public:

      Date();
      ~Date() override = default;

      // arithmetic operators

      ls::Date &operator+(int _value);
      ls::Date &operator-(int _value);
      ls::Date &operator+=(int _value);
      ls::Date &operator-=(int _value);

      // additional functionality

      bool after(const ls::Date &_foreignDate) const;
      bool before(const ls::Date &_foreignDate) const;
      int getDay();
      int getHour();
      int getMinute();
      int getMonth();
      int getSecond();
      time_t getTime() const;
      int getYear();
      void setTime(time_t _timestamp);
      ::std::string toString();

    private:

      time_t timestamp{};
      tm *localTime{};

      void _decrementByDays(int _value);
      void _incrementByDays(int _value);
      void _init();
  };
}

#endif
