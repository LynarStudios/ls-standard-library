/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-05
 *
 * */

#include "Colour.hpp"

test::event::Colour::Colour(const ::std::string &_value) : ls::std::core::Class("Colour")
{
  this->value = _value;
}

test::event::Colour::~Colour() = default;

::std::string test::event::Colour::getValue() const
{
  return this->value;
}
