/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include "DailyNewsAgency.hpp"
#include <ls-std/ls-std-event.hpp>

using ls::std::core::Class;
using ls::std::event::Event;
using std::string;
using test::event::DailyNewsAgency;
using test::event::NewsAgency;

DailyNewsAgency::DailyNewsAgency() : NewsAgency("DailyNewsAgency")
{}

DailyNewsAgency::~DailyNewsAgency() noexcept = default;

void DailyNewsAgency::listen(const Class &_info)
{
  Event event = dynamic_cast<const Event &>(_info);

  if (event.getId() == "SeriousNewsEvent")
  {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void DailyNewsAgency::clear()
{
  this->news.clear();
}

string DailyNewsAgency::getNews()
{
  return this->news;
}
