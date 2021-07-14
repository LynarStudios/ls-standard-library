/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2021-07-14
 *
 * */

#ifndef LS_STD_EVENT_HPP
#define LS_STD_EVENT_HPP

#include <ls_std/base/Class.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <memory>
#include "EventTypes.hpp"

namespace ls_std
{
  class Event : public ls_std::Class
  {
    public:

      explicit Event(const ls_std::event_id &_id);
      ~Event() override = default;

      // additional functionality

      bool addParameter(const ls_std::event_parameter &_eventParameter);
      void clearParameterList();
      ls_std::event_id getId();
      ls_std::event_parameter_list getParameterList();
      bool removeParameter(const ls_std::event_parameter_id &_id);
      void setId(const ls_std::event_id &_id);

    private:

      ls_std::event_id id{};
      ls_std::event_parameter_list parameterList{};

      void _assignId(const ls_std::event_id &_id);
      bool _hasParameter(const ls_std::event_id &_id);
  };
}

#endif
