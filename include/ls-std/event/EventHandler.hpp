/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_EVENT_HANDLER_HPP
#define LS_STD_EVENT_HANDLER_HPP

#include "Event.hpp"
#include "Narrator.hpp"
#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IListener.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL EventHandler : public ls::std::event::Narrator
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

#endif
