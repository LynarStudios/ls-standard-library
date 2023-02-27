/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlParseParameter.hpp>

using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::io::XmlNode;
using ls::std::io::XmlParseParameter;
using std::shared_ptr;

XmlParseParameter::XmlParseParameter() = default;

XmlParseParameter::~XmlParseParameter() = default;

uint8_t XmlParseParameter::getLevel() const
{
  return this->level;
}

shared_ptr<XmlNode> XmlParseParameter::getNode()
{
  return this->node;
}

void XmlParseParameter::setLevel(const uint8_t &_level)
{
  this->level = _level;
}

void XmlParseParameter::setNode(const shared_ptr<XmlNode> &_node)
{
  this->_setNode(_node);
}

void XmlParseParameter::_setNode(const shared_ptr<XmlNode> &_node)
{
  NullPointerArgumentEvaluator{_node, "passed node reference is null!"}.evaluate();
  this->node = _node;
}
