/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2021-05-01
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
  class Event : public ls_std::Class, public ls_std::ISerializable
  {
    public:

      explicit Event(const ls_std::event_id &_id);
      ~Event() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      void addParameter(const ls_std::event_parameter &_eventParameter);
      void clearParameterList();
      ls_std::event_id getId();
      ls_std::event_parameter_list getParameterList();
      void removeParameter(const ls_std::event_parameter_id &_id);
      void setId(const ls_std::event_id &_id);
      void setSerializable(std::shared_ptr<ls_std::ISerializable> _serializable);

    private:

      ls_std::event_id id{};
      ls_std::event_parameter_list parameterList{};
      std::shared_ptr<ls_std::ISerializable> serializable{};

      void _assignId(const ls_std::event_id &_id);
      bool _hasParameter(const ls_std::event_id &_id);
  };
}

#endif
