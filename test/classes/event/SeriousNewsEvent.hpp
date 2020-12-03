/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-27
 *
 * */

#ifndef LS_STD_SERIOUS_NEWS_EVENT_HPP
#define LS_STD_SERIOUS_NEWS_EVENT_HPP

#include <ls_std/ls_std.hpp>
#include <string>

namespace ls_std_test {
  class SeriousNewsEvent : public ls_std::Event {
    public:

      explicit SeriousNewsEvent(const std::string& _news);
      ~SeriousNewsEvent() override = default;
  };
}

#endif
