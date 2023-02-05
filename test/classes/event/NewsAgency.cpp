/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#include "NewsAgency.hpp"

test::event::NewsAgency::NewsAgency(::std::string _agencyName) : agencyName(::std::move(_agencyName))
{}

test::event::NewsAgency::~NewsAgency() = default;

::std::string test::event::NewsAgency::getName()
{
  return this->agencyName;
}
