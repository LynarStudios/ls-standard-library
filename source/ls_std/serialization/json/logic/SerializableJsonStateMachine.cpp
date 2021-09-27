/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2021-05-28
 *
 * */

#include <ls_std/serialization/json/logic/SerializableJsonStateMachine.hpp>
#include <ls_std/serialization/json/logic/SerializableJsonState.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::SerializableJsonStateMachine::SerializableJsonStateMachine(const std::shared_ptr<ls_std::StateMachine> &_value) : ls_std::Class("SerializableJsonStateMachine")
{
  this->_assignValue(_value);
}

ls_std::byte_field ls_std::SerializableJsonStateMachine::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls_std::SerializableJsonStateMachine::unmarshal(const ls_std::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStates();
  this->_unmarshalCurrentState();
  this->value->setMemory(this->jsonObject["memory"]);
  this->value->setName(this->jsonObject["name"]);
}

std::shared_ptr<ls_std::StateMachine> ls_std::SerializableJsonStateMachine::getValue()
{
  return this->value;
}

void ls_std::SerializableJsonStateMachine::setValue(const std::shared_ptr<ls_std::StateMachine> &_value)
{
  this->_assignValue(_value);
}

void ls_std::SerializableJsonStateMachine::_assignValue(const std::shared_ptr<ls_std::StateMachine> &_value)
{
  if (_value == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::SerializableJsonStateMachine::_unmarshalCurrentState()
{
  if (this->jsonObject.contains("currentState"))
  {
    this->value->setStartState(this->jsonObject["currentState"]);
  }
}

void ls_std::SerializableJsonStateMachine::_unmarshalStates()
{
  for (const auto &serializedState : this->jsonObject["states"])
  {
    std::shared_ptr<ls_std::State> state = std::make_shared<ls_std::State>("TMP_ID");
    ls_std::SerializableJsonState{state}.unmarshal(serializedState.dump());
    this->value->addState(state);
  }
}

void ls_std::SerializableJsonStateMachine::_update()
{
  this->jsonObject = {{"memory", this->value->getMemory()},
                      {"name",   this->value->getName()}};

  this->_updateCurrentState();
  this->_updateStates();
}

void ls_std::SerializableJsonStateMachine::_updateCurrentState()
{
  if (this->value->getCurrentState() != nullptr)
  {
    this->jsonObject["currentState"] = this->value->getCurrentState()->getId();
  }
}

void ls_std::SerializableJsonStateMachine::_updateStates()
{
  std::string jsonString{};

  for (const auto &state : this->value->getStates())
  {
    jsonString = ls_std::SerializableJsonState{state.second}.marshal();
    this->jsonObject["states"][state.first] = nlohmann::json::parse(jsonString);
  }
}
