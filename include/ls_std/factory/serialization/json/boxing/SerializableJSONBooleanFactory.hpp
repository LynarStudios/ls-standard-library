/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_SERIALIZABLE_JSON_BOOLEAN_FACTORY_HPP
#define LS_STD_SERIALIZABLE_JSON_BOOLEAN_FACTORY_HPP

#include <ls_std/factory/IFactory.hpp>
#include <memory>

namespace ls_std
{
  class SerializableJSONBooleanFactory : public ls_std::Class, public ls_std::IFactory
  {
    public:

      SerializableJSONBooleanFactory();
      ~SerializableJSONBooleanFactory() override = default;

      std::shared_ptr<ls_std::Class> build() override;
  };
}

#endif
