/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_NARRATOR_HPP
#define LS_STD_NARRATOR_HPP

#include <ls_std/core/Class.hpp>
#include "IListener.hpp"
#include <list>
#include <memory>

namespace ls_std
{
  class Narrator : public ls_std::Class
  {
    public:

      Narrator();
      ~Narrator() override = default;

      bool addListener(const std::shared_ptr<ls_std::IListener> &_listener);
      void clear();
      std::list<std::shared_ptr<ls_std::IListener>> getListeners();
      bool removeListener(const std::shared_ptr<ls_std::IListener> &_listener);
      void tell(const ls_std::Class &_info);

    private:

      std::list<std::shared_ptr<ls_std::IListener>> listeners{};
  };
}

#endif
