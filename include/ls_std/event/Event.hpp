/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2022-05-09
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
  namespace std
  {
    namespace event
    {
      class Event : public ls::std::core::Class
      {
        public:

          explicit Event(const ls::std::event::event_id &_id);
          ~Event() override = default;

          // additional functionality

          bool addParameter(const ls::std::event::event_parameter &_eventParameter);
          void clearParameterList();
          ls::std::event::event_id getId();
          ls::std::event::event_parameter_list getParameterList();
          bool removeParameter(const ls::std::event::event_parameter_id &_id);
          void setId(const ls::std::event::event_id &_id);

        private:

          ls::std::event::event_id id{};
          ls::std::event::event_parameter_list parameterList{};

          void _assignId(const ls::std::event::event_id &_id);
          bool _hasParameter(const ls::std::event::event_id &_id);
      };
    }
  }
}

#endif
