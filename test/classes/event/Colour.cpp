/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2022-05-14
 *
 * */

#include "Colour.hpp"

ls_std_event_test::Colour::Colour(const ::std::string &_value) : ls::std::core::Class("Colour")
{
  this->value = _value;
}

::std::string ls_std_event_test::Colour::getValue() const
{
  return this->value;
}
