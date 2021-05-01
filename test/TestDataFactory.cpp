/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2021-04-23
 *
 * */

#include "TestDataFactory.hpp"

ls_std::StateMachine ls_std_test::TestDataFactory::createStateMachine()
{
  ls_std::StateMachine stateMachine{"test_machine"};

  std::shared_ptr<ls_std::State> stateA = std::make_shared<ls_std::State>("A");
  std::shared_ptr<ls_std::State> stateB = std::make_shared<ls_std::State>("B");
  std::shared_ptr<ls_std::State> stateC = std::make_shared<ls_std::State>("C");
  std::shared_ptr<ls_std::State> stateD = std::make_shared<ls_std::State>("D");
  std::shared_ptr<ls_std::State> stateE = std::make_shared<ls_std::State>("E");

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

std::shared_ptr<ls_std::XMLNode> ls_std_test::TestDataFactory::createXMLContent()
{
  std::shared_ptr<ls_std::XMLNode> root = std::make_shared<ls_std::XMLNode>("dialog");
  std::shared_ptr<ls_std::XMLAttribute> attribute{};
  std::shared_ptr<ls_std::XMLNode> child{};
  std::shared_ptr<ls_std::XMLNode> text{};

  attribute = std::make_shared<ls_std::XMLAttribute>("name");
  attribute->setValue("dungeon_001");
  root->addAttributeToEnd(attribute);

  child = std::make_shared<ls_std::XMLNode>("dialogUnit");
  attribute = std::make_shared<ls_std::XMLAttribute>("id");
  attribute->setValue("001");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls_std::XMLNode>("text");
  text->setValue("Hello!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  child = std::make_shared<ls_std::XMLNode>("dialogUnit");
  attribute = std::make_shared<ls_std::XMLAttribute>("id");
  attribute->setValue("002");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls_std::XMLNode>("text");
  text->setValue("Hello again!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  return root;
}
