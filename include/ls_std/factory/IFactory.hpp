/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_I_FACTORY_HPP
#define LS_STD_I_FACTORY_HPP

#include <memory>
#include <ls_std/core/Class.hpp>

namespace ls_std
{
  class IFactory
  {
    public:

      IFactory() = default;
      ~IFactory() = default;

      virtual std::shared_ptr<ls_std::Class> build() = 0;
  };
}

#endif
