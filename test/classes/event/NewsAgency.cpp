/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-04-23
 *
 * */

#include "NewsAgency.hpp"

ls_std_test::NewsAgency::NewsAgency(std::string _agencyName) : agencyName(std::move(_agencyName))
{}

std::string ls_std_test::NewsAgency::getName()
{
  return this->agencyName;
}
