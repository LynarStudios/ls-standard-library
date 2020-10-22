/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-20
 * Changed:         2020-09-20
 *
 * *//*


#ifndef LS_STD_SERIALIZABLE_XML_STATE_CONNECTION_HPP
#define LS_STD_SERIALIZABLE_XML_STATE_CONNECTION_HPP

#include "../../../base/Class.hpp"
#include "../../ISerializable.hpp"
#include "../../../logic/StateConnection.hpp"
#include <memory>
#include <tinyxml2.h>

namespace ls_std {
  class SerializableXMLStateConnection : public Class, public ISerializable {
    public:

      explicit SerializableXMLStateConnection(std::shared_ptr<StateConnection> _value);
      ~SerializableXMLStateConnection() = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      std::shared_ptr<StateConnection> getValue();
      void setValue(std::shared_ptr<StateConnection> _value);

    private:

      tinyxml2::XMLDocument document {};
      std::shared_ptr<StateConnection> value {};

      void _clear();
      void _unmarshalCondition();
      void _unmarshalConnectionId();
      void _unmarshalId();
      void _update();
  };
}

#endif
*/
