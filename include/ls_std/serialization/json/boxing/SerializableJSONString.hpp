/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-30
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_STRING_HPP
#define LS_STD_SERIALIZABLE_JSON_STRING_HPP

#include <memory>
#include <ls_std/lib/nlohmann_json/include/nlohmann/json.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/boxing/String.hpp>

namespace ls_std
{
  class SerializableJSONString : public ls_std::Class, public ls_std::ISerializable
  {
    public:

      explicit SerializableJSONString(const std::shared_ptr<ls_std::String> &_value);
      ~SerializableJSONString() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      std::shared_ptr<ls_std::String> getValue();
      void setValue(const std::shared_ptr<ls_std::String> &_value);

    private:

      nlohmann::json jsonObject{};
      std::shared_ptr<ls_std::String> value{};

      void _assignValue(const std::shared_ptr<ls_std::String> &_value);
      void _update();
  };
}

#endif
