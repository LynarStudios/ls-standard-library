/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-28
 *
 * */

#ifndef LS_STD_EVENT_HANDLER_HPP
#define LS_STD_EVENT_HANDLER_HPP

#include <ls_std/base/Class.hpp>
#include <list>
#include <memory>
#include <ls_std/logic/IListener.hpp>
#include "Event.hpp"

namespace ls_std {
  class EventHandler : public ls_std::Class {
    public:

      explicit EventHandler(ls_std::event_id  _id);
      ~EventHandler() override = default;

      void addListener(const std::shared_ptr<ls_std::IListener>& _listener);
      ls_std::event_id getId();
      void notify(const ls_std::Event& _event);
      void removeListener(const std::shared_ptr<ls_std::IListener>& _listener);

    private:

      ls_std::event_id id {};
      std::list<std::shared_ptr<ls_std::IListener>> listeners {};

      void _addListener(const std::shared_ptr<ls_std::IListener>& _listener);
      bool _hasListener(const std::shared_ptr<ls_std::IListener>& _listener);
      void _removeListener(const std::shared_ptr<ls_std::IListener>& _listener);
  };
}

#endif
