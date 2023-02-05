/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_SERIOUS_NEWS_EVENT_HPP
#define LS_STD_SERIOUS_NEWS_EVENT_HPP

#include <ls-std/ls-std-event.hpp>
#include <string>

namespace ls_std_event_test
{
  class SeriousNewsEvent : public ls::std::event::Event
  {
    public:

      explicit SeriousNewsEvent(const ::std::string &_news);
      ~SeriousNewsEvent() override;
  };
}

#endif
