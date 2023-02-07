/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-07-03
 *
 * */

#ifndef LS_STD_EVENT_HPP
#define LS_STD_EVENT_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/core/interface/ISerializable.hpp>
#include <memory>
#include <ls_std/event/types/EventTypes.hpp>
#include <ls_std/os/dynamic_goal.hpp>

using namespace ls::std::event::type;

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL Event : public ls::std::core::Class
  {
    public:

      explicit Event(const event_id &_id);
      ~Event() override = default;

      // additional functionality

      bool addParameter(const event_parameter &_eventParameter);
      void clearParameterList();
      event_id getId();
      event_parameter_list getParameterList();
      bool removeParameter(const event_parameter_id &_id);
      void setId(const event_id &_id);

    private:

      event_id id{};
      event_parameter_list parameterList{};

      void _assignId(const event_id &_id);
      bool _hasParameter(const event_id &_id);
  };
}

#endif
