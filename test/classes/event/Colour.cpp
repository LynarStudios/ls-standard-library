/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-23
 *
 * */

#include "Colour.hpp"

using ls::std::core::Class;
using std::string;
using test::event::Colour;

Colour::Colour(const string &_value) : Class("Colour")
{
  this->value = _value;
}

Colour::~Colour() = default;

string Colour::getValue() const
{
  return this->value;
}
