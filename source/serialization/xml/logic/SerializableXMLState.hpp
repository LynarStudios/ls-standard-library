/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * */

#ifndef LS_STD_SERIALIZABLE_XML_STATE_HPP
#define LS_STD_SERIALIZABLE_XML_STATE_HPP

#include "../../../base/Class.hpp"
#include "../../ISerializable.hpp"
#include "../../../logic/State.hpp"
#include <memory>
#include <tinyxml2.h>

namespace ls_std {
  class SerializableXMLState : public Class, public ISerializable {
    public:

      explicit SerializableXMLState(std::shared_ptr<State> _value);
      ~SerializableXMLState() = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      std::shared_ptr<State> getValue();
      void setValue(std::shared_ptr<State> _value);

    private:

      tinyxml2::XMLDocument document {};
      std::shared_ptr<State> value {};

      void _clear();
      void _unmarshalConnections(tinyxml2::XMLElement* _root);
      void _unmarshalId(tinyxml2::XMLElement* _root);
      void _update();
      void _updateStates();
  };
}

#endif
