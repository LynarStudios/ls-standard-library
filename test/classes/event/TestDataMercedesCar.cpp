/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-04
 *
 * */

#include "TestDataMercedesCar.hpp"
#include "Colour.hpp"

ls_std_event_test::TestDataMercedesCar::TestDataMercedesCar() : TestDataCar()
{
  this->setColor("blue");
}

void ls_std_event_test::TestDataMercedesCar::listen(const ls::std::core::Class &_info)
{
  this->setColor(dynamic_cast<const ls_std_event_test::Colour &>(_info).getValue());
}
