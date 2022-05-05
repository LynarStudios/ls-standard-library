/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2022-05-05
 *
 * */

#include "TestDataFactory.hpp"

ls::StateMachine ls_std_test::TestDataFactory::createStateMachine()
{
  ls::StateMachine stateMachine{"test_machine"};

  std::shared_ptr<ls::State> stateA = std::make_shared<ls::State>("A");
  std::shared_ptr<ls::State> stateB = std::make_shared<ls::State>("B");
  std::shared_ptr<ls::State> stateC = std::make_shared<ls::State>("C");
  std::shared_ptr<ls::State> stateD = std::make_shared<ls::State>("D");
  std::shared_ptr<ls::State> stateE = std::make_shared<ls::State>("E");

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

std::shared_ptr<ls::XmlNode> ls_std_test::TestDataFactory::createXmlContent()
{
  std::shared_ptr<ls::XmlNode> root = std::make_shared<ls::XmlNode>("dialog");
  std::shared_ptr<ls::XmlAttribute> attribute{};
  std::shared_ptr<ls::XmlNode> child{};
  std::shared_ptr<ls::XmlNode> text{};

  attribute = std::make_shared<ls::XmlAttribute>("name");
  attribute->setValue("dungeon_001");
  root->addAttributeToEnd(attribute);

  child = std::make_shared<ls::XmlNode>("dialogUnit");
  attribute = std::make_shared<ls::XmlAttribute>("id");
  attribute->setValue("001");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls::XmlNode>("text");
  text->setValue("Hello!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  child = std::make_shared<ls::XmlNode>("dialogUnit");
  attribute = std::make_shared<ls::XmlAttribute>("id");
  attribute->setValue("002");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls::XmlNode>("text");
  text->setValue("Hello again!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  return root;
}
