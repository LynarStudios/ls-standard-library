/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-30
 *
 * */

#ifndef STRING_HPP
#define STRING_HPP

#include "IBoxing.hpp"
#include "../base/Class.hpp"
#include "../serialization/ISerializable.hpp"
#include "../io/IStorable.hpp"
#include <string>
#include <memory>

namespace ls_std {
  class String : public Class, public IBoxing, public ISerializable, public IStorable {
    public:

      String();
      explicit String(std::string _value);
      ~String() = default;

      // conversion operator

      operator const char*() const; // do not make explicit!
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

      ls_std::byte_field load() override;
      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      void save(const ls_std::byte_field& _data) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      bool contains(const std::string& _text);
      bool endsWith(const std::string& _text);
      bool equalsIgnoreCase(String _string);
      bool equalsIgnoreCase(std::string _text);
      std::string padLeft(size_t _width, const char _fillCharacter);
      std::string padRight(size_t _width, const char _fillCharacter);
      std::string reverse();
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      void setStorable(std::shared_ptr<IStorable> _storable);
      bool startsWith(const std::string& _text);
      std::string toLowerCase();
      std::string toUpperCase();

    private:

      std::shared_ptr<ISerializable> serializable {};
      std::shared_ptr<IStorable> storable {};
      std::string value {};

      static std::string _buildCharacterChain(size_t _amount, const char _fillCharacter);
      static std::string _createFillContent(const std::string& _text, size_t _width, const char _fillCharacter);
  };
}

#endif
