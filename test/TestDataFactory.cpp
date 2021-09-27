/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-16
 * Changed:         2021-05-02
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

std::shared_ptr<ls_std::XmlNode> ls_std_test::TestDataFactory::createXmlContent()
{
  std::shared_ptr<ls_std::XmlNode> root = std::make_shared<ls_std::XmlNode>("dialog");
  std::shared_ptr<ls_std::XmlAttribute> attribute{};
  std::shared_ptr<ls_std::XmlNode> child{};
  std::shared_ptr<ls_std::XmlNode> text{};

  attribute = std::make_shared<ls_std::XmlAttribute>("name");
  attribute->setValue("dungeon_001");
  root->addAttributeToEnd(attribute);

  child = std::make_shared<ls_std::XmlNode>("dialogUnit");
  attribute = std::make_shared<ls_std::XmlAttribute>("id");
  attribute->setValue("001");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls_std::XmlNode>("text");
  text->setValue("Hello!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  child = std::make_shared<ls_std::XmlNode>("dialogUnit");
  attribute = std::make_shared<ls_std::XmlAttribute>("id");
  attribute->setValue("002");
  child->addAttributeToEnd(attribute);
  text = std::make_shared<ls_std::XmlNode>("text");
  text->setValue("Hello again!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  return root;
}
