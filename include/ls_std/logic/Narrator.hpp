/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_NARRATOR_HPP
#define LS_STD_NARRATOR_HPP

#include <ls_std/core/Class.hpp>
#include "IListener.hpp"
#include <list>
#include <memory>

namespace ls
{
  namespace std
  {
    namespace logic
    {
      class Narrator : public ls::std::core::Class
      {
        public:

          Narrator();
          ~Narrator() override = default;

          bool addListener(const ::std::shared_ptr<ls::std::logic::IListener> &_listener);
          void clear();
          ::std::list<::std::shared_ptr<ls::std::logic::IListener>> getListeners();
          bool removeListener(const ::std::shared_ptr<ls::std::logic::IListener> &_listener);
          void tell(const ls::std::core::Class &_info);

        private:

          ::std::list<::std::shared_ptr<ls::std::logic::IListener>> listeners{};
      };
    }
  }
}

#endif
