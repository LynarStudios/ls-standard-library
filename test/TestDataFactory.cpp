/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2022-05-11
 *
 * */

#include "TestDataFactory.hpp"

ls::std::logic::StateMachine ls_std_test::TestDataFactory::createStateMachine()
{
  ls::std::logic::StateMachine stateMachine{"test_machine"};

  std::shared_ptr<ls::std::logic::State> stateA = std::make_shared<ls::std::logic::State>("A");
  std::shared_ptr<ls::std::logic::State> stateB = std::make_shared<ls::std::logic::State>("B");
  std::shared_ptr<ls::std::logic::State> stateC = std::make_shared<ls::std::logic::State>("C");
  std::shared_ptr<ls::std::logic::State> stateD = std::make_shared<ls::std::logic::State>("D");
  std::shared_ptr<ls::std::logic::State> stateE = std::make_shared<ls::std::logic::State>("E");

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

std::shared_ptr<ls::std::io::XmlNode> ls_std_test::TestDataFactory::createXmlContent()
{
  std::shared_ptr<ls::std::io::XmlNode> root = std::make_shared<ls::std::io::XmlNode>("dialog");
  std::shared_ptr<ls::std::io::XmlAttribute> attribute{};
  std::shared_ptr<ls::std::io::XmlNode> child{};
  std::shared_ptr<ls::std::io::XmlNode> text{};

  attribute = std::make_shared<ls::std::io::XmlAttribute>("name");
  attribute->setValue("dungeon_001");
  root->addAttributeToEnd(attribute);

  child = std::make_shared<ls::std::io::XmlNode>("dialogUnit");
  attribute = std::make_shared<ls::std::io::XmlAttribute>("id");
  attribute->setValue("001");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls::std::io::XmlNode>("text");
  text->setValue("Hello!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  child = std::make_shared<ls::std::io::XmlNode>("dialogUnit");
  attribute = std::make_shared<ls::std::io::XmlAttribute>("id");
  attribute->setValue("002");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls::std::io::XmlNode>("text");
  text->setValue("Hello again!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  return root;
}
