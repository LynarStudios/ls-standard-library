/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include "NewsAgency.hpp"

using std::move;
using std::string;
using test::event::NewsAgency;

NewsAgency::NewsAgency(string _agencyName) : agencyName(::move(_agencyName))
{}

NewsAgency::~NewsAgency() = default;

string NewsAgency::getName()
{
  return this->agencyName;
}
