/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-11-14
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_FLOAT_HPP
#define LS_STD_SERIALIZABLE_JSON_FLOAT_HPP

#include <memory>
#include <json.hpp>
#include "../../base/Class.hpp"
#include "../ISerializable.hpp"
#include "../../boxing/Float.hpp"

namespace ls_std {
  class SerializableJSONFloat : public Class, public ISerializable {
    public:

      explicit SerializableJSONFloat(std::shared_ptr<ls_std::Float> _value);
      ~SerializableJSONFloat() override = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      std::shared_ptr<ls_std::Float> value {};
      nlohmann::json jsonObject {};

      void _update();
  };
}

#endif
