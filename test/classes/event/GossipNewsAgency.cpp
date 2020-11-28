/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-28
 *
 * */

#include "GossipNewsAgency.hpp"

ls_std_test::GossipNewsAgency::GossipNewsAgency() : ls_std_test::NewsAgency("GossipNewsAgency")
{}

void ls_std_test::GossipNewsAgency::clear()
{
  this->news.clear();
}

std::string ls_std_test::GossipNewsAgency::getNews()
{
  return this->news;
}

void ls_std_test::GossipNewsAgency::listen(const ls_std::Class &_info)
{
  ls_std::Event event = dynamic_cast<const ls_std::Event&>(_info);

  if(event.getId() == "SeriousNewsEvent") {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }

  if(event.getId() == "GossipNewsEvent") {
    this->news = this->getName() + ": " + event.getParameterList().at("news");
  }
}

void ls_std_test::GossipNewsAgency::subscribe(const ls_std::event_id &_id)
{
  // TODO: check event handler existence

  this->eventHandlers.at(_id)->addListener(this->shared_from_this());
}

void ls_std_test::GossipNewsAgency::unsubscribe(const ls_std::event_id &_id)
{
  // TODO: check event handler existence

  this->eventHandlers.at(_id)->removeListener(this->shared_from_this());
}

void ls_std_test::GossipNewsAgency::addEventHandler(const std::shared_ptr<ls_std::EventHandler> &_eventHandler)
{
  // TODO: check event handler existence

  std::pair<ls_std::event_id, std::shared_ptr<ls_std::EventHandler>> entry = std::make_pair(_eventHandler->getId(), _eventHandler);
  this->eventHandlers.insert(entry);
}
