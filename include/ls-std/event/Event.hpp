/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_EVENT_HPP
#define LS_STD_EVENT_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/core/type/EventTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL Event : public ls::std::core::Class
  {
    public:

      explicit Event(const ls::std::core::type::event_id &_id);
      ~Event() noexcept override;

      // additional functionality

      bool addParameter(const ls::std::core::type::event_parameter &_eventParameter); // nodiscard is optional here
      void clearParameterList();
      [[nodiscard]] ls::std::core::type::event_id getId();
      [[nodiscard]] ls::std::core::type::event_parameter_list getParameterList();
      bool removeParameter(const ls::std::core::type::event_parameter_id &_id); // nodiscard is optional here
      void setId(const ls::std::core::type::event_id &_id);

    private:

      ls::std::core::type::event_id id{};
      ls::std::core::type::event_parameter_list parameterList{};

      void _assignId(const ls::std::core::type::event_id &_id);
      [[nodiscard]] bool _hasParameter(const ls::std::core::type::event_id &_id);
  };
}

#endif
