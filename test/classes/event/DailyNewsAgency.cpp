/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-04-23
 *
 * */

#include "DailyNewsAgency.hpp"

ls_std_test::DailyNewsAgency::DailyNewsAgency() : ls_std_test::NewsAgency("DailyNewsAgency")
{}

void ls_std_test::DailyNewsAgency::listen(const ls_std::Class &_info)
{
  ls_std::Event event = dynamic_cast<const ls_std::Event &>(_info);

  if (event.getId() == "SeriousNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void ls_std_test::DailyNewsAgency::clear()
{
  this->news.clear();
}

std::string ls_std_test::DailyNewsAgency::getNews()
{
  return this->news;
}
