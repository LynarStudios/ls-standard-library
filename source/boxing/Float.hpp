/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-09-04
 *
 * */

#ifndef LS_STD_FLOAT_HPP
#define LS_STD_FLOAT_HPP

#include <memory>
#include "../base/Class.hpp"
#include "IBoxing.hpp"
#include "../serialization/ISerializable.hpp"

namespace ls_std {
  class Float : public Class, public IBoxing, public ISerializable {
    public:

      Float();
      explicit Float(float _value);
      ~Float() = default;

      // conversion operator

      operator float() const; // do not make explicit!

      // assignment operators

      Float& operator=(float _value);

      // arithmetic operators

      float operator-() const;
      float operator+(const Float& _float) const;
      float operator+(float _value) const;
      float operator*(const Float& _float) const;
      float operator*(float _value) const;
      float operator-(const Float& _float) const;
      float operator-(float _value) const;
      float operator/(const Float& _float) const;
      float operator/(float _value) const;

      // compound operators

      Float& operator+=(const Float& _float);
      Float& operator+=(float _value);
      Float& operator-=(const Float& _float);
      Float& operator-=(float _value);
      Float& operator*=(const Float& _float);
      Float& operator*=(float _value);
      Float& operator/=(const Float& _float);
      Float& operator/=(float _value);

      // comparison operators

      bool operator==(const Float& _float) const;
      bool operator==(float _value) const;
      bool operator!=(const Float& _float) const;
      bool operator!=(float _value) const;
      bool operator>(const Float& _float) const;
      bool operator>(float _value) const;
      bool operator>=(const Float& _float) const;
      bool operator>=(float _value) const;
      bool operator<(const Float& _float) const;
      bool operator<(float _value) const;
      bool operator<=(const Float& _float) const;
      bool operator<=(float _value) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      float getEpsilon();
      float getValue();
      void setEpsilon(float _epsilon);
      void setSerializable(std::shared_ptr<ISerializable> _serializable);

    private:

      std::shared_ptr<ISerializable> serializable {};

      float value {};
      float epsilon {};
  };
}

#endif
