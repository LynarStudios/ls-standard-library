/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/xml/XmlParseParameter.hpp>

ls::std::io::XmlParseParameter::XmlParseParameter() = default;

ls::std::io::XmlParseParameter::~XmlParseParameter() = default;

uint8_t ls::std::io::XmlParseParameter::getLevel() const
{
  return this->level;
}

::std::shared_ptr<ls::std::io::XmlNode> ls::std::io::XmlParseParameter::getNode()
{
  return this->node;
}

void ls::std::io::XmlParseParameter::setLevel(const uint8_t &_level)
{
  this->level = _level;
}

void ls::std::io::XmlParseParameter::setNode(const ::std::shared_ptr<ls::std::io::XmlNode> &_node)
{
  this->_setNode(_node);
}

void ls::std::io::XmlParseParameter::_setNode(const ::std::shared_ptr<ls::std::io::XmlNode> &_node)
{
  if (_node == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->node = _node;
}
