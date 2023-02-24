/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-23
 *
 * */

#include "TestDataFactory.hpp"

using ls::std::io::XmlAttribute;
using ls::std::io::XmlNode;
using std::make_shared;
using std::shared_ptr;
using test::io::TestDataFactory;

TestDataFactory::TestDataFactory() = default;

TestDataFactory::~TestDataFactory() = default;

shared_ptr<XmlNode> TestDataFactory::createXmlContent()
{
  shared_ptr<XmlNode> root = make_shared<XmlNode>("dialog");
  shared_ptr<XmlAttribute> attribute{};
  shared_ptr<XmlNode> child{};
  shared_ptr<XmlNode> text{};

  attribute = make_shared<XmlAttribute>("name");
  attribute->setValue("dungeon_001");
  root->addAttributeToEnd(attribute);

  child = make_shared<XmlNode>("dialogUnit");
  attribute = make_shared<XmlAttribute>("id");
  attribute->setValue("001");
  child->addAttributeToEnd(attribute);
  text = make_shared<XmlNode>("text");
  text->setValue("Hello!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  child = make_shared<XmlNode>("dialogUnit");
  attribute = make_shared<XmlAttribute>("id");
  attribute->setValue("002");
  child->addAttributeToEnd(attribute);
  text = make_shared<XmlNode>("text");
  text->setValue("Hello again!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  return root;
}
