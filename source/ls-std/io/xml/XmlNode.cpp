/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2023-02-24
 *
 * */

#include <algorithm>
#include <iterator>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/xml/XmlNode.hpp>
#include <numeric>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::io::XmlAttribute;
using ls::std::io::XmlNode;
using std::accumulate;
using std::any_of;
using std::back_inserter;
using std::copy_if;
using std::find;
using std::list;
using std::move;
using std::shared_ptr;
using std::string;

XmlNode::XmlNode(string _name) : Class("XmlNode"), name(::move(_name))
{}

XmlNode::~XmlNode() noexcept = default;

bool XmlNode::addAttributeAfter(const shared_ptr<XmlAttribute> &_attribute, const string &_name)
{
  bool added{};
  auto iterator = this->attributes.begin();
  NullPointerArgumentEvaluator{_attribute, "passed attribute reference for add attempt is null!"}.evaluate();
  EmptyStringArgumentEvaluator{_name, "xml node name is empty!"}.evaluate();

  if (!this->_hasAttribute(_attribute->getName()))
  {
    while (iterator != this->attributes.end())
    {
      if ((*iterator)->getName() == _name)
      {
        iterator++;
        this->attributes.insert(iterator, _attribute);
        added = true;
        break;
      }

      iterator++;
    }
  }

  return added;
}

bool XmlNode::addAttributeBefore(const shared_ptr<XmlAttribute> &_attribute, const string &_name)
{
  bool added{};
  auto iterator = this->attributes.begin();
  NullPointerArgumentEvaluator{_attribute, "passed attribute reference for add attempt is null!"}.evaluate();
  EmptyStringArgumentEvaluator{_name, "xml node name is empty!"}.evaluate();

  if (!this->_hasAttribute(_attribute->getName()))
  {
    while (iterator != this->attributes.end())
    {
      if ((*iterator)->getName() == _name)
      {
        this->attributes.insert(iterator, _attribute);
        added = true;
        break;
      }

      iterator++;
    }
  }

  return added;
}

bool XmlNode::addAttributeToBeginning(const shared_ptr<XmlAttribute> &_attribute)
{
  bool added{};
  NullPointerArgumentEvaluator{_attribute, "passed attribute reference for add attempt is null!"}.evaluate();

  if (!_hasAttribute(_attribute->getName()))
  {
    this->attributes.push_front(_attribute);
    added = true;
  }

  return added;
}

bool XmlNode::addAttributeToEnd(const shared_ptr<XmlAttribute> &_attribute)
{
  bool added{};
  NullPointerArgumentEvaluator{_attribute, "passed attribute reference for add attempt is null!"}.evaluate();

  if (!_hasAttribute(_attribute->getName()))
  {
    this->attributes.push_back(_attribute);
    added = true;
  }

  return added;
}

bool XmlNode::addChildAfter(const shared_ptr<XmlNode> &_child, const shared_ptr<XmlNode> &_search)
{
  bool added{};
  auto iterator = this->children.begin();
  NullPointerArgumentEvaluator{_child, "passed child node reference for add attempt is null!"}.evaluate();
  NullPointerArgumentEvaluator{_search, "passed search node reference for add attempt is null!"}.evaluate();

  if (!this->_hasChild(_child))
  {
    while (iterator != this->children.end())
    {
      if (*iterator == _search)
      {
        iterator++;
        this->children.insert(iterator, _child);
        added = true;
        break;
      }

      iterator++;
    }
  }

  return added;
}

bool XmlNode::addChildBefore(const shared_ptr<XmlNode> &_child, const shared_ptr<XmlNode> &_search)
{
  bool added{};
  auto iterator = this->children.begin();
  NullPointerArgumentEvaluator{_child, "passed child node reference for add attempt is null!"}.evaluate();
  NullPointerArgumentEvaluator{_search, "passed search node reference for add attempt is null!"}.evaluate();

  if (!this->_hasChild(_child))
  {
    while (iterator != this->children.end())
    {
      if (*iterator == _search)
      {
        this->children.insert(iterator, _child);
        added = true;
        break;
      }

      iterator++;
    }
  }

  return added;
}

bool XmlNode::addChildToBeginning(const shared_ptr<XmlNode> &_child)
{
  bool added{};
  NullPointerArgumentEvaluator{_child, "passed child node reference for add attempt is null!"}.evaluate();

  if (!this->_hasChild(_child))
  {
    this->children.push_front(_child);
    added = true;
  }

  return added;
}

bool XmlNode::addChildToEnd(const shared_ptr<XmlNode> &_child)
{
  bool added{};
  NullPointerArgumentEvaluator{_child, "passed child node reference for add attempt is null!"}.evaluate();

  if (!this->_hasChild(_child))
  {
    this->children.push_back(_child);
    added = true;
  }

  return added;
}

void XmlNode::clearValue()
{
  this->value.clear();
}

list<shared_ptr<XmlAttribute>> XmlNode::getAttributes()
{
  return this->attributes;
}

list<shared_ptr<XmlNode>> XmlNode::getChildren()
{
  return this->children;
}

list<shared_ptr<XmlNode>> XmlNode::getChildren(const string &_name)
{
  list<shared_ptr<XmlNode>> childrenWithName{};
  copy_if(this->children.begin(), this->children.end(), back_inserter(childrenWithName), [_name](const shared_ptr<XmlNode> &_node) { return _node->getName() == _name; });

  return childrenWithName;
}

string XmlNode::getName()
{
  return this->name;
}

string XmlNode::getValue()
{
  return this->value;
}

bool XmlNode::hasAttribute(const string &_name)
{
  return this->_hasAttribute(_name);
}

bool XmlNode::hasChild(const string &_name)
{
  return this->_hasChild(_name);
}

bool XmlNode::hasChild(const shared_ptr<XmlNode> &_child)
{
  return this->_hasChild(_child);
}

bool XmlNode::removeFirstAttribute()
{
  bool isValidOperation = !this->attributes.empty();

  if (isValidOperation)
  {
    this->attributes.pop_front();
  }

  return isValidOperation;
}

bool XmlNode::removeLastAttribute()
{
  bool isValidOperation = !this->attributes.empty();

  if (isValidOperation)
  {
    this->attributes.pop_back();
  }

  return isValidOperation;
}

bool XmlNode::removeFirstChild()
{
  bool isValidOperation = !this->children.empty();

  if (isValidOperation)
  {
    this->children.pop_front();
  }

  return isValidOperation;
}

bool XmlNode::removeLastChild()
{
  bool isValidOperation = !this->children.empty();

  if (isValidOperation)
  {
    this->children.pop_back();
  }

  return isValidOperation;
}

void XmlNode::setName(const string &_name)
{
  this->_assignName(_name);
}

void XmlNode::setValue(const string &_value)
{
  this->_assignValue(_value);
}

string XmlNode::toXml()
{
  return this->_toXml_(0);
}

string XmlNode::_toXml_(uint8_t _tabSize)
{
  string xmlStream{};

  xmlStream += XmlNode::_getTab(_tabSize);
  xmlStream += this->_toXmlOpenTag();
  xmlStream += this->_toXmlAttributes();
  xmlStream += this->_toXmlOpenTagClose();
  xmlStream += this->_toXmlValue();
  xmlStream += this->_toXmlChildren(_tabSize + TAB_SIZE);
  xmlStream += this->value.empty() ? XmlNode::_getTab(_tabSize) : "";
  xmlStream += this->_toXmlCloseTag() + "\n";

  return xmlStream;
}

void XmlNode::_assignName(const string &_name)
{
  EmptyStringArgumentEvaluator{_name, "xml node name is empty!"}.evaluate();
  this->name = _name;
}

void XmlNode::_assignValue(const string &_value)
{
  EmptyStringArgumentEvaluator{_value, "xml node value is empty!"}.evaluate();
  this->value = _value;
}

string XmlNode::_getTab(uint8_t _tabSize)
{
  string tab{};

  for (uint8_t index = 0; index < _tabSize; index++)
  {
    tab += " ";
  }

  return tab;
}

bool XmlNode::_hasAttribute(const string &_name)
{
  EmptyStringArgumentEvaluator{_name, "xml attribute name is empty!"}.evaluate();
  return any_of(this->attributes.begin(), this->attributes.end(), [_name](const shared_ptr<XmlAttribute> &_attribute) { return _attribute->getName() == _name; });
}

bool XmlNode::_hasChild(const shared_ptr<XmlNode> &_child)
{
  NullPointerArgumentEvaluator{_child, "passed child node reference for check attempt is null!"}.evaluate();
  return find(this->children.begin(), this->children.end(), _child) != this->children.end();
}

bool XmlNode::_hasChild(const string &_name)
{
  EmptyStringArgumentEvaluator{_name, "xml child node name is empty!"}.evaluate();
  return any_of(this->children.begin(), this->children.end(), [_name](const shared_ptr<XmlNode> &_node) { return _node->getName() == _name; });
}

string XmlNode::_toXmlAttributes()
{
  return accumulate(this->attributes.begin(), this->attributes.end(), string{}, [](string stream, const shared_ptr<XmlAttribute> &_attribute) { return ::move(stream) + " " + _attribute->toXml(); });
}

string XmlNode::_toXmlChildren(uint8_t _tabSize)
{
  return accumulate(this->children.begin(), this->children.end(), string{}, [_tabSize](string stream, const shared_ptr<XmlNode> &_child) { return ::move(stream) + _child->_toXml_(_tabSize); });
}

string XmlNode::_toXmlCloseTag()
{
  string stream{};

  if (!this->children.empty() || !this->value.empty())
  {
    stream = "</" + this->name + ">";
  }

  return stream;
}

string XmlNode::_toXmlOpenTag()
{
  return "<" + this->name;
}

string XmlNode::_toXmlOpenTagClose()
{
  string stream{};

  if (this->children.empty() && this->value.empty())
  {
    stream = " />";
  }
  else
  {
    stream = ">";
  }

  return stream;
}

string XmlNode::_toXmlValue()
{
  return this->value.empty() ? "\n" : this->value;
}
