/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-08
 *
 * */

#include "SeriousNewsEvent.hpp"

ls_std_test::SeriousNewsEvent::SeriousNewsEvent(const std::string &_news) : ls::std::event::Event("SeriousNewsEvent")
{
  ls::std::event::event_parameter newsParameter = std::make_pair("news", _news);
  this->addParameter(newsParameter);
}
