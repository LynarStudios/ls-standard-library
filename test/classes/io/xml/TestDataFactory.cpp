/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-05
 *
 * */

#include "TestDataFactory.hpp"

test::io::TestDataFactory::TestDataFactory() = default;

test::io::TestDataFactory::~TestDataFactory() = default;

::std::shared_ptr<ls::std::io::XmlNode> test::io::TestDataFactory::createXmlContent()
{
  ::std::shared_ptr<ls::std::io::XmlNode> root = ::std::make_shared<ls::std::io::XmlNode>("dialog");
  ::std::shared_ptr<ls::std::io::XmlAttribute> attribute{};
  ::std::shared_ptr<ls::std::io::XmlNode> child{};
  ::std::shared_ptr<ls::std::io::XmlNode> text{};

  attribute = ::std::make_shared<ls::std::io::XmlAttribute>("name");
  attribute->setValue("dungeon_001");
  root->addAttributeToEnd(attribute);

  child = ::std::make_shared<ls::std::io::XmlNode>("dialogUnit");
  attribute = ::std::make_shared<ls::std::io::XmlAttribute>("id");
  attribute->setValue("001");
  child->addAttributeToEnd(attribute);
  text = ::std::make_shared<ls::std::io::XmlNode>("text");
  text->setValue("Hello!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  child = ::std::make_shared<ls::std::io::XmlNode>("dialogUnit");
  attribute = ::std::make_shared<ls::std::io::XmlAttribute>("id");
  attribute->setValue("002");
  child->addAttributeToEnd(attribute);
  text = ::std::make_shared<ls::std::io::XmlNode>("text");
  text->setValue("Hello again!");
  child->addChildToEnd(text);
  root->addChildToEnd(child);

  return root;
}
