/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-04
 * Changed:         2020-09-04
 *
 * */

#ifndef SERIALIZABLE_JSON_DOUBLE_HPP
#define SERIALIZABLE_JSON_DOUBLE_HPP

#include <memory>
#include <json.hpp>
#include "../../base/Class.hpp"
#include "../ISerializable.hpp"
#include "../../boxing/Double.hpp"

namespace ls_std {
  class SerializableJSONDouble : public Class, public ISerializable {
    public:

      explicit SerializableJSONDouble(std::shared_ptr<ls_std::Double> _doubleValue);
      ~SerializableJSONDouble() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

    private:

      std::shared_ptr<ls_std::Double> doubleValue {};
      nlohmann::json jsonObject {};

      void _update();
  };
}

#endif