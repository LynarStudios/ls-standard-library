/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-10
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include "../base/Class.hpp"

namespace ls_std {
  class State : public Class {
    public:

      explicit State(std::string _id);
      ~State() = default;

      bool addStateConnection(const std::string& _connectionId, const std::shared_ptr<State>& _connectedState);
      std::unordered_map<std::string, std::shared_ptr<State>> getConnectedStates();
      std::string getId();

    private:

      std::unordered_map<std::string, std::shared_ptr<State>> connectedStates {};
      std::string id {};

      bool _stateIsConnected(const std::string& _id);
  };
}

#endif
