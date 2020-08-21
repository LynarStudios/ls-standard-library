/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2020-08-21
 *
 * */

#ifndef SERIALIZABLE_JSON_INTEGER_HPP
#define SERIALIZABLE_JSON_INTEGER_HPP

#include "../../base/Class.hpp"
#include "../ISerializable.hpp"
#include "../../boxing/Integer.hpp"
#include <json.hpp>

namespace ls_std {
  class SerializableJSONInteger : public Class, ISerializable {
    public:

      explicit SerializableJSONInteger(std::shared_ptr<ls_std::Integer> _integer);
      ~SerializableJSONInteger() = default;

      const ls_std::byte* marshal() override;
      void unmarshal(const ls_std::byte* _data) override;

    private:

      std::shared_ptr<ls_std::Integer> integer {};
      nlohmann::json jsonObject {};

      void _update();
  };
}

#endif
