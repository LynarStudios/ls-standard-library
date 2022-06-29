/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-06-29
 *
 * */

#ifndef LS_STD_EVENT_HANDLER_HPP
#define LS_STD_EVENT_HANDLER_HPP

#include <ls_std/core/Class.hpp>
#include <list>
#include <memory>
#include <ls_std/core/interface/IListener.hpp>
#include <ls_std/os/dynamic_goal.hpp>
#include "Event.hpp"
#include "Narrator.hpp"

namespace ls
{
  namespace std
  {
    namespace event
    {
      class DYNAMIC_GOAL EventHandler : public ls::std::event::Narrator
      {
        public:

          explicit EventHandler(const ls::std::core::type::event_id &_id);
          ~EventHandler() override = default;

          ls::std::core::type::event_id getId();

        private:

          ls::std::core::type::event_id id{};

          void _assignId(const ls::std::core::type::event_id &_id);
      };
    }
  }
}

#endif
