/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_BOOLEAN_HPP
#define LS_STD_SERIALIZABLE_JSON_BOOLEAN_HPP

#include <memory>
#include <json.hpp>
#include "../../../../../include/ls_std/base/Class.hpp"
#include "../../ISerializable.hpp"
#include "../../../boxing/Boolean.hpp"

namespace ls_std {
  class SerializableJSONBoolean : public Class, public ISerializable {
    public:

      explicit SerializableJSONBoolean(std::shared_ptr<ls_std::Boolean> _value);
      ~SerializableJSONBoolean() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      std::shared_ptr<ls_std::Boolean> value {};
      nlohmann::json jsonObject {};

      void _update();
  };
}

#endif
