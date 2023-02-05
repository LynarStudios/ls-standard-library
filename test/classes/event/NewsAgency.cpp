/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#include "NewsAgency.hpp"

ls_std_event_test::NewsAgency::NewsAgency(::std::string _agencyName) : agencyName(::std::move(_agencyName))
{}

ls_std_event_test::NewsAgency::~NewsAgency() = default;

::std::string ls_std_event_test::NewsAgency::getName()
{
  return this->agencyName;
}
