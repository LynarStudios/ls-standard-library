/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-23
 *
 * */

#include "SeriousNewsEvent.hpp"

using ls::std::core::type::event_parameter;
using ls::std::event::Event;
using std::make_pair;
using std::string;
using test::event::SeriousNewsEvent;

SeriousNewsEvent::SeriousNewsEvent(const string &_news) : Event("SeriousNewsEvent")
{
  event_parameter newsParameter = make_pair("news", _news);
  this->addParameter(newsParameter);
}

SeriousNewsEvent::~SeriousNewsEvent() noexcept = default;
