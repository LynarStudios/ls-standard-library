/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-21
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_INTEGER_HPP
#define LS_STD_SERIALIZABLE_JSON_INTEGER_HPP

#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/base/Class.hpp>
#include <ls_std/boxing/Integer.hpp>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>

namespace ls_std
{
  class SerializableJSONInteger : public ls_std::Class, public ls_std::ISerializable
  {
    public:

      explicit SerializableJSONInteger(const std::shared_ptr<ls_std::Integer> &_value);
      ~SerializableJSONInteger() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      std::shared_ptr<ls_std::Integer> getValue();
      void setValue(const std::shared_ptr<ls_std::Integer> &_value);

    private:

      std::shared_ptr<ls_std::Integer> value{};
      nlohmann::json jsonObject{};

      void _assignValue(const std::shared_ptr<ls_std::Integer> &_value);
      void _update();
  };
}

#endif
