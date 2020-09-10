/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-10
 * Changed:         2020-09-10
 *
 * */

#ifndef LS_STD_STATE_CONNECTION_HPP
#define LS_STD_STATE_CONNECTION_HPP

#include <memory>
#include <atomic>
#include "../base/Class.hpp"
#include "State.hpp"

namespace ls_std {
  class StateConnection : public Class {
    public:

      explicit StateConnection(std::string _connectionId, std::shared_ptr<State> _state);
      ~StateConnection() = default;

      std::string getConnectionId();
      std::shared_ptr<State> getState();
      bool isPassable();
      void updatePassCondition(bool _condition);

    private:

      std::atomic<bool> condition {};
      std::string connectionId {};
      std::shared_ptr<State> state {};
  };
}

#endif
