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
#include <list>
#include "../base/Class.hpp"

namespace ls_std {
  class State : public Class {
    public:

      explicit State(std::string  _id);
      ~State() = default;

      bool addStateConnection(const std::shared_ptr<State>& _connectedState);
      std::list<std::shared_ptr<State>> getConnectedStates();
      std::string getId();
      bool isAccessible() const;
      void removeStateConnection(const std::string& _id);
      void updateAccessCondition(bool _enteredCondition);

    private:

      bool accessCondition {};
      std::list<std::shared_ptr<State>> connectedStates {};
      std::string id {};

      bool _stateIsConnected(const std::string& _id);
  };
}

#endif
