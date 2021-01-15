/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-29
 *
 * */

#include "GossipNewsAgency.hpp"

ls_std_test::GossipNewsAgency::GossipNewsAgency() : ls_std_test::NewsAgency("GossipNewsAgency")
{}

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

void ls_std_test::GossipNewsAgency::clear()
{
  this->news.clear();
}

std::string ls_std_test::GossipNewsAgency::getNews()
{
  return this->news;
}