/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/boxing/String.hpp>
#include "TestDataMercedesCar.hpp"

ls_std_test::TestDataMercedesCar::TestDataMercedesCar() : TestDataCar()
{
  this->setColor("blue");
}

void ls_std_test::TestDataMercedesCar::listen(const ls_std::Class &_info)
{
  this->setColor(dynamic_cast<const ls_std::String &>(_info));
}
