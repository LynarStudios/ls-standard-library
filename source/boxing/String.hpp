/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-18
 *
 * */

#ifndef STRING_HPP
#define STRING_HPP

#include "IBoxing.hpp"
#include "../base/Class.hpp"
#include <string>

namespace ls_std {
  class String : public Class, IBoxing {
    public:

      String();
      explicit String(std::string _value);
      ~String() = default;

      // conversion operator

      operator const char*() const; // do not make explicit! FIXME: is that save?
      operator std::string() const; // do not make explicit!

      // assignment operators

      String& operator=(std::string _value);

      // arithmetic operators

      std::string operator+(String _string) const;
      std::string operator+(const std::string& _string) const;
      std::string operator+(const char* _string) const;
      std::string operator-(int _number);

      // compound operators

      String& operator+=(String _string);
      String& operator+=(const std::string& _text);

      // comparison operators

      bool operator==(String _string);
      bool operator==(const std::string& _value);
      bool operator==(const char* _value);
      bool operator!=(String _string);
      bool operator!=(const std::string& _value);
      bool operator!=(const char* _value);

      // implementation

      void parse(std::string _parseText) override;
      std::string toString() override;

      // additional functionality

      bool contains(const std::string& _text);
      bool endsWith(const std::string& _text);
      bool equalsIgnoreCase(String _string);
      bool equalsIgnoreCase(std::string _text);
      std::string reverse();
      bool startsWith(const std::string& _text);
      std::string toLowerCase();
      std::string toUpperCase();

    private:

      std::string value {};
  };
}

#endif
