/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_EVENT_HPP
#define LS_STD_EVENT_HPP

#include <ls_std/core/Class.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <memory>
#include "EventTypes.hpp"

namespace ls
{
  class Event : public ls::Class
  {
    public:

      explicit Event(const ls::event_id &_id);
      ~Event() override = default;

      // additional functionality

      bool addParameter(const ls::event_parameter &_eventParameter);
      void clearParameterList();
      ls::event_id getId();
      ls::event_parameter_list getParameterList();
      bool removeParameter(const ls::event_parameter_id &_id);
      void setId(const ls::event_id &_id);

    private:

      ls::event_id id{};
      ls::event_parameter_list parameterList{};

      void _assignId(const ls::event_id &_id);
      bool _hasParameter(const ls::event_id &_id);
  };
}

#endif
