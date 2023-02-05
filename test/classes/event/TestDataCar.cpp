/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-05
 *
 * */

#include "TestDataCar.hpp"

test::event::TestDataCar::TestDataCar() : color("white")
{}

test::event::TestDataCar::~TestDataCar() = default;

::std::string test::event::TestDataCar::getColor()
{
  return this->color;
}

void test::event::TestDataCar::setColor(::std::string _color)
{
  this->color = ::std::move(_color);
}
