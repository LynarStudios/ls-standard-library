/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-05
 *
 * */

#include "TestDataCar.hpp"

ls_std_event_test::TestDataCar::TestDataCar() : color("white")
{}

ls_std_event_test::TestDataCar::~TestDataCar() = default;

::std::string ls_std_event_test::TestDataCar::getColor()
{
  return this->color;
}

void ls_std_event_test::TestDataCar::setColor(::std::string _color)
{
  this->color = ::std::move(_color);
}
