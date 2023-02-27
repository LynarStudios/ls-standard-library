/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-23
 *
 * */

#include "TestDataMercedesCar.hpp"
#include "Colour.hpp"

using ls::std::core::Class;
using test::event::Colour;
using test::event::TestDataMercedesCar;

TestDataMercedesCar::TestDataMercedesCar() : TestDataCar()
{
  this->setColor("blue");
}

TestDataMercedesCar::~TestDataMercedesCar() noexcept = default;

void TestDataMercedesCar::listen(const Class &_info)
{
  this->setColor(dynamic_cast<const Colour &>(_info).getValue());
}
