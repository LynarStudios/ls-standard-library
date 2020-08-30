/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2020-08-30
 *
 * */

#ifndef SERIALIZABLE_JSON_STRING_HPP
#define SERIALIZABLE_JSON_STRING_HPP

#include <memory>
#include <json.hpp>
#include "../../serialization/ISerializable.hpp"
#include "../../boxing/String.hpp"

namespace ls_std {
  class SerializableJSONString : public Class, public ISerializable {
    public:

      explicit SerializableJSONString(std::shared_ptr<ls_std::String> _value);
      ~SerializableJSONString() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      nlohmann::json jsonObject {};
      std::shared_ptr<ls_std::String> value {};

      void _update();
  };
}

#endif
