/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2020-11-14
 *
 * */

#ifndef LS_STD_NARRATOR_HPP
#define LS_STD_NARRATOR_HPP

#include "../base/Class.hpp"
#include "IListener.hpp"
#include <list>
#include <memory>

namespace ls_std {
  class Narrator : public Class {
    public:

      Narrator();
      ~Narrator() override = default;

      void addListener(const std::shared_ptr<ls_std::IListener>& _listener);
      void clear();
      std::list<std::shared_ptr<ls_std::IListener>> getListeners();
      void notifyListeners(const ls_std::Class& _info);
      void removeListener(const std::shared_ptr<ls_std::IListener>& _listener);

    private:

      std::list<std::shared_ptr<ls_std::IListener>> listeners {};
  };
}

#endif
