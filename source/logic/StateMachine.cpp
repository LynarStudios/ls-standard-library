/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-05
 * Changed:         2020-09-07
 *
 * */

#include "StateMachine.hpp"

ls_std::StateMachine::StateMachine() : Class("StateMachine")
{}

bool ls_std::StateMachine::addState(std::shared_ptr<State> _state) {
  bool added {};
  this->states.insert({_state->getId(), std::move(_state)});

  return added;
}

bool ls_std::StateMachine::_stateExists(const std::string &_id) {
  return this->states.find(_id) != this->states.end();
}
