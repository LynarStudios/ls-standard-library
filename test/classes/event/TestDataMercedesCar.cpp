/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-14
 *
 * */

#include "Colour.hpp"
#include "TestDataMercedesCar.hpp"

ls_std_test::TestDataMercedesCar::TestDataMercedesCar() : TestDataCar()
{
  this->setColor("blue");
}

void ls_std_test::TestDataMercedesCar::listen(const ls::std::core::Class &_info)
{
  this->setColor(dynamic_cast<const ls_std_event_test::Colour &>(_info).getValue());
}
