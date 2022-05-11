/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_I_FACTORY_HPP
#define LS_STD_I_FACTORY_HPP

#include <memory>
#include "ls_std/core/Class.hpp"

// TODO: is this really necessary to have?

namespace ls
{
  namespace std
  {
    namespace core
    {
      class IFactory
      {
        public:

          IFactory() = default;
          ~IFactory() = default;

          virtual ::std::shared_ptr<ls::std::core::Class> build() = 0;
      };
    }
  }
}

#endif
