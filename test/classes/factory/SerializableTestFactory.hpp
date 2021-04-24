/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24s
 * Changed:         2021-04-24
 *
 * */

#ifndef LS_STD_SERIALIZABLE_TEST_FACTORY_HPP
#define LS_STD_SERIALIZABLE_TEST_FACTORY_HPP

#include <ls_std/factory/IFactory.hpp>

namespace ls_std_test
{
  class SerializableTestFactory : public ls_std::IFactory
  {
    public:

      SerializableTestFactory() = default;
      ~SerializableTestFactory() = default;

      std::shared_ptr<ls_std::Class> build() override;
  };
}

#endif
