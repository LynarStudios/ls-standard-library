/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#include "DailyNewsAgency.hpp"
#include <ls-std/ls-std-event.hpp>

test::event::DailyNewsAgency::DailyNewsAgency() : test::event::NewsAgency("DailyNewsAgency")
{}

test::event::DailyNewsAgency::~DailyNewsAgency() = default;

void test::event::DailyNewsAgency::listen(const ls::std::core::Class &_info)
{
  ls::std::event::Event event = dynamic_cast<const ls::std::event::Event &>(_info);

  if (event.getId() == "SeriousNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void test::event::DailyNewsAgency::clear()
{
  this->news.clear();
}

::std::string test::event::DailyNewsAgency::getNews()
{
  return this->news;
}
