/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_STRING_HPP
#define LS_STD_STRING_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/core/types/Types.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>
#include <vector>

namespace ls::std::boxing
{
  class LS_STD_DYNAMIC_GOAL String : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
  {
    public:

      String();
      explicit String(::std::string _value);
      ~String() override;

      // conversion operator

      operator const char *() const; // do not make explicit!
      operator ::std::string() const; // do not make explicit!

      // assignment operators

      ls::std::boxing::String &operator=(::std::string _value);

      // arithmetic operators

      ::std::string operator+(ls::std::boxing::String _string) const;
      ::std::string operator+(const ::std::string &_string) const;
      ::std::string operator+(const char *_string) const;
      ::std::string operator-(int _number);

      // compound operators

      ls::std::boxing::String &operator+=(ls::std::boxing::String _string);
      ls::std::boxing::String &operator+=(const ::std::string &_text);

      // comparison operators

      bool operator==(ls::std::boxing::String _string);
      bool operator==(const ::std::string &_value);
      bool operator==(const char *_value);
      bool operator!=(ls::std::boxing::String _string);
      bool operator!=(const ::std::string &_value);
      bool operator!=(const char *_value);

      // implementation

      void parse(::std::string _parseText) override;
      ::std::string toString() override;

      // additional functionality

      bool contains(const ::std::string &_text);
      bool endsWith(const ::std::string &_text);
      bool equalsIgnoreCase(ls::std::boxing::String _string);
      bool equalsIgnoreCase(::std::string _text);
      ::std::vector<ls::std::core::type::byte> getByteData();
      ::std::string padLeft(size_t _width, char _fillCharacter);
      ::std::string padRight(size_t _width, char _fillCharacter);
      ::std::string reverse();
      bool startsWith(const ::std::string &_text);
      ::std::string toLowerCase();
      ::std::string toUpperCase();

    private:

      ::std::string value{};

      static ::std::string _buildCharacterChain(size_t _amount, char _fillCharacter);
      static ::std::string _createFillContent(const ::std::string &_text, size_t _width, char _fillCharacter);
  };
}

#endif
