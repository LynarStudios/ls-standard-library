/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_EVENT_HANDLER_HPP
#define LS_STD_EVENT_HANDLER_HPP

#include <ls_std/core/Class.hpp>
#include <list>
#include <memory>
#include <ls_std/core/interface/IListener.hpp>
#include "Event.hpp"
#include <ls_std/logic/Narrator.hpp>

namespace ls
{
  namespace std
  {
    namespace event
    {
      class EventHandler : public ls::std::logic::Narrator
      {
        public:

          explicit EventHandler(const ls::std::event::event_id &_id);
          ~EventHandler() override = default;

          ls::std::event::event_id getId();

        private:

          ls::std::event::event_id id{};

          void _assignId(const ls::std::event::event_id &_id);
      };
    }
  }
}

#endif
