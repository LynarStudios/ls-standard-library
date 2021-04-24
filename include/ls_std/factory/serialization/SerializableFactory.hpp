/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-04-24
 *
 * */

#ifndef LS_STD_SERIALIZABLE_FACTORY_HPP
#define LS_STD_SERIALIZABLE_FACTORY_HPP

#include <ls_std/base/Class.hpp>
#include <map>
#include <string>
#include <memory>
#include <ls_std/factory/IFactory.hpp>

namespace ls_std
{
  class SerializableFactory : public ls_std::Class
  {
    public:

      SerializableFactory();
      ~SerializableFactory() override = default;

      bool addFactory(const std::pair<std::string, std::shared_ptr<ls_std::IFactory>> &_factoryInsertion);
      std::shared_ptr<ls_std::Class> build(const std::string &_relatedObjectName);
      bool clear();
      bool hasFactory(const std::string &_relatedObjectName);
      bool removeFactory(const std::string &_relatedObjectName);

    private:

      std::map<std::string, std::shared_ptr<ls_std::IFactory>> factories{};

      bool _hasFactory(const std::string &_relatedObjectName);
      void _init();
  };
}

#endif
