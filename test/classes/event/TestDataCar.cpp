/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-23
 *
 * */

#include "TestDataCar.hpp"

using std::move;
using std::string;
using test::event::TestDataCar;

TestDataCar::TestDataCar() : color("white")
{}

TestDataCar::~TestDataCar() = default;

string TestDataCar::getColor()
{
  return this->color;
}

void TestDataCar::setColor(string _color)
{
  this->color = ::move(_color);
}
