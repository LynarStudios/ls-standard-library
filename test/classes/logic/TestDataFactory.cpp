/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2022-05-20
 *
 * */

#include "TestDataFactory.hpp"

ls::std::logic::StateMachine ls_std_logic_test::TestDataFactory::createStateMachine()
{
  ls::std::logic::StateMachine stateMachine{"test_machine"};

  ::std::shared_ptr<ls::std::logic::State> stateA = ::std::make_shared<ls::std::logic::State>("A");
  ::std::shared_ptr<ls::std::logic::State> stateB = ::std::make_shared<ls::std::logic::State>("B");
  ::std::shared_ptr<ls::std::logic::State> stateC = ::std::make_shared<ls::std::logic::State>("C");
  ::std::shared_ptr<ls::std::logic::State> stateD = ::std::make_shared<ls::std::logic::State>("D");
  ::std::shared_ptr<ls::std::logic::State> stateE = ::std::make_shared<ls::std::logic::State>("E");

  // add states

  stateMachine.addState(stateA);
  stateMachine.addState(stateB);
  stateMachine.addState(stateC);
  stateMachine.addState(stateD);
  stateMachine.addState(stateE);

  // add connections / see state_machine_test.png

  stateA->addStateConnection("AB", stateB);
  stateB->addStateConnection("BC", stateC);
  stateB->addStateConnection("BD", stateD);
  stateC->addStateConnection("CB", stateB);
  stateC->addStateConnection("CE", stateE);
  stateD->addStateConnection("DE", stateE);

  return stateMachine;
}
