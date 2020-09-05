/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-05
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <vector>
#include "../base/Class.hpp"

namespace ls_std {
  class State : public Class {
    public:

      State();
      ~State() = default;

    private:

      std::vector<std::shared_ptr<State>> connectedStates {};
  };
}

#endif
