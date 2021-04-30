/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-30
 * Changed:         2021-04-30
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_EVENT_FACTORY_HPP
#define LS_STD_SERIALIZABLE_JSON_EVENT_FACTORY_HPP

#include <ls_std/factory/IFactory.hpp>
#include <memory>

namespace ls_std
{
  class SerializableJSONEventFactory : public ls_std::Class, public ls_std::IFactory
  {
    public:

      SerializableJSONEventFactory();
      ~SerializableJSONEventFactory() override = default;

      std::shared_ptr<ls_std::Class> build() override;
  };
}

#endif
