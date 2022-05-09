/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-09
 *
 * */

#include "DailyNewsAgency.hpp"

ls_std_test::DailyNewsAgency::DailyNewsAgency() : ls_std_test::NewsAgency("DailyNewsAgency")
{}

void ls_std_test::DailyNewsAgency::listen(const ls::std::core::Class &_info)
{
  ls::std::event::Event event = dynamic_cast<const ls::std::event::Event &>(_info);

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
