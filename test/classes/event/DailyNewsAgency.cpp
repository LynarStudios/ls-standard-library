/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-27
 *
 * */

#include "DailyNewsAgency.hpp"

ls_std_test::DailyNewsAgency::DailyNewsAgency() : ls_std_test::NewsAgency("DailyNewsAgency")
{}

void ls_std_test::DailyNewsAgency::clear()
{
  this->news.clear();
}

std::string ls_std_test::DailyNewsAgency::getNews()
{
  return this->news;
}

void ls_std_test::DailyNewsAgency::listen(const ls_std::Class &_info)
{
  ls_std::Event event = dynamic_cast<const ls_std::Event&>(_info);

  if(event.getId() == "SeriousNewsEvent") {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void ls_std_test::DailyNewsAgency::subscribe(const ls_std::event_id &_id)
{
  // TODO: check event handler existence

//  std::shared_ptr<ls_std_test::DailyNewsAgency> listener = this->shared_from_this();
  this->eventHandlers.at(_id)->subscribe(this->shared_from_this());
}

void ls_std_test::DailyNewsAgency::unsubscribe(const ls_std::event_id &_id)
{
  // TODO: check event handler existence

  this->eventHandlers.at(_id)->unsubscribe(this->shared_from_this());
}

void ls_std_test::DailyNewsAgency::addEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  // TODO: check event handler existence

  std::pair<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> entry = std::make_pair(_eventHandler->getId(), _eventHandler);
  this->eventHandlers.insert(entry);
}
