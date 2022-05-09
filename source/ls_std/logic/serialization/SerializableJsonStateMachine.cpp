/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2022-05-09
 *
 * */

#include "ls_std/logic/serialization/SerializableJsonStateMachine.hpp"
#include "ls_std/logic/serialization/SerializableJsonState.hpp"
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::SerializableJsonStateMachine::SerializableJsonStateMachine(const ::std::shared_ptr<ls::StateMachine> &_value) : ls::std::core::Class("SerializableJsonStateMachine")
{
  this->_assignValue(_value);
}

ls::std::core::byte_field ls::SerializableJsonStateMachine::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::SerializableJsonStateMachine::unmarshal(const ls::std::core::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStates();
  this->_unmarshalCurrentState();
  this->value->setMemory(this->jsonObject["memory"]);
  this->value->setName(this->jsonObject["name"]);
}

std::shared_ptr<ls::StateMachine> ls::SerializableJsonStateMachine::getValue()
{
  return this->value;
}

void ls::SerializableJsonStateMachine::setValue(const ::std::shared_ptr<ls::StateMachine> &_value)
{
  this->_assignValue(_value);
}

void ls::SerializableJsonStateMachine::_assignValue(const ::std::shared_ptr<ls::StateMachine> &_value)
{
  if (_value == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::SerializableJsonStateMachine::_unmarshalCurrentState()
{
  if (this->jsonObject.contains("currentState"))
  {
    this->value->setStartState(this->jsonObject["currentState"]);
  }
}

void ls::SerializableJsonStateMachine::_unmarshalStates()
{
  for (const auto &serializedState : this->jsonObject["states"])
  {
    ::std::shared_ptr<ls::State> state = ::std::make_shared<ls::State>("TMP_ID");
    ls::SerializableJsonState{state}.unmarshal(serializedState.dump());
    this->value->addState(state);
  }
}

void ls::SerializableJsonStateMachine::_update()
{
  this->jsonObject = {{"memory", this->value->getMemory()},
                      {"name",   this->value->getName()}};

  this->_updateCurrentState();
  this->_updateStates();
}

void ls::SerializableJsonStateMachine::_updateCurrentState()
{
  if (this->value->getCurrentState() != nullptr)
  {
    this->jsonObject["currentState"] = this->value->getCurrentState()->getId();
  }
}

void ls::SerializableJsonStateMachine::_updateStates()
{
  ::std::string jsonString{};

  for (const auto &state : this->value->getStates())
  {
    jsonString = ls::SerializableJsonState{state.second}.marshal();
    this->jsonObject["states"][state.first] = nlohmann::json::parse(jsonString);
  }
}
