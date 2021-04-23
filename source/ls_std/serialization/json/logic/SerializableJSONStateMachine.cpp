/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/serialization/logic/SerializableJSONStateMachine.hpp>
#include <ls_std/serialization/logic/SerializableJSONState.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJSONStateMachine::SerializableJSONStateMachine(const std::shared_ptr<ls_std::StateMachine> &_value) : ls_std::Class("SerializableJSONStateMachine")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJSONStateMachine::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJSONStateMachine::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStates();
  this->_unmarshalCurrentState();
  this->value->setMemory(this->jsonObject["memory"]);
  this->value->setName(this->jsonObject["name"]);
}

std::shared_ptr<ls_std::StateMachine> ls_std::SerializableJSONStateMachine::getValue()
{
  return this->value;
}

void ls_std::SerializableJSONStateMachine::setValue(const std::shared_ptr<ls_std::StateMachine> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJSONStateMachine::_assignValue(const std::shared_ptr<ls_std::StateMachine> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJSONStateMachine::_unmarshalCurrentState()
{
  if (this->jsonObject.contains("currentState"))
  {
    this->value->setStartState(this->jsonObject["currentState"]);
  }
}

void ls_std::SerializableJSONStateMachine::_unmarshalStates()
{
  for (const auto &serializedState : this->jsonObject["states"])
  {
    std::shared_ptr<ls_std::State> state = std::make_shared<ls_std::State>("");
    ls_std::SerializableJSONState{state}.unmarshal(serializedState.dump());
    this->value->addState(state);
  }
}

void ls_std::SerializableJSONStateMachine::_update()
{
  this->jsonObject = {{"memory", this->value->getMemory()},
                      {"name",   this->value->getName()}};

  this->_updateCurrentState();
  this->_updateStates();
}

void ls_std::SerializableJSONStateMachine::_updateCurrentState()
{
  if (this->value->getCurrentState() != nullptr)
  {
    this->jsonObject["currentState"] = this->value->getCurrentState()->getId();
  }
}

void ls_std::SerializableJSONStateMachine::_updateStates()
{
  std::string jsonString{};

  for (const auto &state : this->value->getStates())
  {
    jsonString = ls_std::SerializableJSONState{state.second}.marshal();
    this->jsonObject["states"][state.first] = nlohmann::json::parse(jsonString);
  }
}
