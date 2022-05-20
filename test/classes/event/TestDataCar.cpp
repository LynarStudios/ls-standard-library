/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-20
 *
 * */

#include "TestDataCar.hpp"

ls_std_event_test::TestDataCar::TestDataCar() : color("white")
{}

::std::string ls_std_event_test::TestDataCar::getColor()
{
  return this->color;
}

void ls_std_event_test::TestDataCar::setColor(::std::string _color)
{
  this->color = ::std::move(_color);
}
