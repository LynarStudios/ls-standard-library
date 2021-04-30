/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2021-04-30
 *
 * */

#ifndef LS_STD_STATE_HPP
#define LS_STD_STATE_HPP

#include <memory>
#include <unordered_map>
#include <ls_std/base/Class.hpp>
#include "StateMachineTypes.hpp"
#include "StateConnection.hpp"
#include <ls_std/serialization/ISerializable.hpp>

namespace ls_std
{
  class State : public ls_std::Class, public ls_std::ISerializable
  {
    public:

      explicit State(ls_std::StateId _id);
      ~State() override = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      bool addStateConnection(const ls_std::StateConnectionId &_connectionId, const std::shared_ptr<ls_std::State> &_connectedState);
      bool addStateConnection(const std::shared_ptr<ls_std::StateConnection> &_connection);
      void clearConnections();
      std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> getConnectedStates();
      ls_std::StateId getId();
      bool hasConnection(const ls_std::StateConnectionId &_connectionId);
      void setId(ls_std::StateId _id);
      void setSerializable(std::shared_ptr<ls_std::ISerializable> _serializable);

    private:

      std::unordered_map<ls_std::StateConnectionId, std::shared_ptr<ls_std::StateConnection>> connectedStates{};
      ls_std::StateId id{};
      std::shared_ptr<ISerializable> serializable{};

      void _clearConnections();
      bool _hasConnection(const ls_std::StateConnectionId &_connectionId);
  };
}

#endif
