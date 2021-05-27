/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2021-05-27
 *
 * */

#ifndef LS_STD_EVENT_HANDLER_HPP
#define LS_STD_EVENT_HANDLER_HPP

#include <ls_std/base/Class.hpp>
#include <list>
#include <memory>
#include <ls_std/logic/IListener.hpp>
#include "Event.hpp"
#include <ls_std/logic/Narrator.hpp>

namespace ls_std
{
  class EventHandler : public ls_std::Narrator
  {
    public:

      explicit EventHandler(const ls_std::event_id& _id);
      ~EventHandler() override = default;

      ls_std::event_id getId();

    private:

      ls_std::event_id id{};

      void _assignId(const ls_std::event_id& _id);
  };
}

#endif
