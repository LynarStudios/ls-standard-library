/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-15
 *
 * */

#ifndef DATE_HPP
#define DATE_HPP

#include "../base/Class.hpp"
#include <ctime>

namespace ls_std {
  class Date : public Class {
    public:

      Date();
      ~Date() = default;

      // arithmetic operators

      Date& operator+(int _value);

      // additional functionality

      bool after(const Date& foreignDate) const;
      bool before(const Date& foreignDate) const;
      int getDay();
      int getHour();
      int getMinute();
      int getMonth();
      int getSecond();
      time_t getTime() const;
      int getYear();
      void setTime(time_t _timestamp);
      std::string toString();

    private:

      time_t timestamp {};
      tm* localTime {};

      void init();
  };
}

#endif
