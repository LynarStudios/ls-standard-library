/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-05
 *
 * */

#include "TestDataMercedesCar.hpp"
#include "Colour.hpp"

test::event::TestDataMercedesCar::TestDataMercedesCar() : TestDataCar()
{
  this->setColor("blue");
}

test::event::TestDataMercedesCar::~TestDataMercedesCar() = default;

void test::event::TestDataMercedesCar::listen(const ls::std::core::Class &_info)
{
  this->setColor(dynamic_cast<const test::event::Colour &>(_info).getValue());
}
