/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-17
 * Changed:         2022-05-20
 *
 * */

#include <ls_std/logic/serialization/SerializableJsonStateMachine.hpp>
#include <ls_std/logic/serialization/SerializableJsonState.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::logic::SerializableJsonStateMachine::SerializableJsonStateMachine(const ::std::shared_ptr<ls::std::logic::StateMachine> &_value) : ls::std::core::Class("SerializableJsonStateMachine")
{
  this->_assignValue(_value);
}

ls::std::core::type::byte_field ls::std::logic::SerializableJsonStateMachine::marshal()
{
  this->_update();
  return this->jsonObject.dump();
}

void ls::std::logic::SerializableJsonStateMachine::unmarshal(const ls::std::core::type::byte_field &_data)
{
  this->jsonObject = nlohmann::json::parse(_data);

  this->_unmarshalStates();
  this->_unmarshalCurrentState();
  this->value->setMemory(this->jsonObject["memory"]);
  this->value->setName(this->jsonObject["name"]);
}

::std::shared_ptr<ls::std::logic::StateMachine> ls::std::logic::SerializableJsonStateMachine::getValue()
{
  return this->value;
}

void ls::std::logic::SerializableJsonStateMachine::setValue(const ::std::shared_ptr<ls::std::logic::StateMachine> &_value)
{
  this->_assignValue(_value);
}

void ls::std::logic::SerializableJsonStateMachine::_assignValue(const ::std::shared_ptr<ls::std::logic::StateMachine> &_value)
{
  if (_value == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::std::logic::SerializableJsonStateMachine::_unmarshalCurrentState()
{
  if (this->jsonObject.contains("currentState"))
  {
    this->value->setStartState(this->jsonObject["currentState"]);
  }
}

void ls::std::logic::SerializableJsonStateMachine::_unmarshalStates()
{
  for (const auto &serializedState : this->jsonObject["states"])
  {
    ::std::shared_ptr<ls::std::logic::State> state = ::std::make_shared<ls::std::logic::State>("TMP_ID");
    ls::std::logic::SerializableJsonState{state}.unmarshal(serializedState.dump());
    this->value->addState(state);
  }
}

void ls::std::logic::SerializableJsonStateMachine::_update()
{
  this->jsonObject = {{"memory", this->value->getMemory()},
                      {"name",   this->value->getName()}};

  this->_updateCurrentState();
  this->_updateStates();
}

void ls::std::logic::SerializableJsonStateMachine::_updateCurrentState()
{
  if (this->value->getCurrentState() != nullptr)
  {
    this->jsonObject["currentState"] = this->value->getCurrentState()->getId();
  }
}

void ls::std::logic::SerializableJsonStateMachine::_updateStates()
{
  ::std::string jsonString{};

  for (const auto &state : this->value->getStates())
  {
    jsonString = ls::std::logic::SerializableJsonState{state.second}.marshal();
    this->jsonObject["states"][state.first] = nlohmann::json::parse(jsonString);
  }
}
