/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2022-05-09
 *
 * */

#include <ls_std/io/xml/XmlNode.hpp>
#include <ls_std/core/utils/STLUtils.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::XmlNode::XmlNode(::std::string _name)
    : ls::std::core::Class("XmlNode"),
      name(::std::move(_name))
{}

bool ls::XmlNode::addAttributeAfter(const ::std::shared_ptr<ls::XmlAttribute> &_attribute, const ::std::string &_name)
{
  bool added{};
  auto iterator = this->attributes.begin();
  _checkIfAttributeReferenceIsValid(_attribute);
  _checkIfNameIsNotEmpty(_name);

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

bool ls::XmlNode::addAttributeBefore(const ::std::shared_ptr<ls::XmlAttribute> &_attribute, const ::std::string &_name)
{
  bool added{};
  auto iterator = this->attributes.begin();
  _checkIfAttributeReferenceIsValid(_attribute);
  _checkIfNameIsNotEmpty(_name);

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

bool ls::XmlNode::addAttributeToBeginning(const ::std::shared_ptr<ls::XmlAttribute> &_attribute)
{
  bool added{};
  _checkIfAttributeReferenceIsValid(_attribute);

  if (!_hasAttribute(_attribute->getName()))
  {
    this->attributes.push_front(_attribute);
    added = true;
  }

  return added;
}

bool ls::XmlNode::addAttributeToEnd(const ::std::shared_ptr<ls::XmlAttribute> &_attribute)
{
  bool added{};
  _checkIfAttributeReferenceIsValid(_attribute);

  if (!_hasAttribute(_attribute->getName()))
  {
    this->attributes.push_back(_attribute);
    added = true;
  }

  return added;
}

bool ls::XmlNode::addChildAfter(const ::std::shared_ptr<ls::XmlNode> &_child, const ::std::shared_ptr<ls::XmlNode> &_search)
{
  bool added{};
  auto iterator = this->children.begin();
  _checkIfNodeReferenceIsValid(_child);
  _checkIfNodeReferenceIsValid(_search);

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

bool ls::XmlNode::addChildBefore(const ::std::shared_ptr<ls::XmlNode> &_child, const ::std::shared_ptr<ls::XmlNode> &_search)
{
  bool added{};
  auto iterator = this->children.begin();
  _checkIfNodeReferenceIsValid(_child);
  _checkIfNodeReferenceIsValid(_search);

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

bool ls::XmlNode::addChildToBeginning(const ::std::shared_ptr<ls::XmlNode> &_child)
{
  bool added{};
  _checkIfNodeReferenceIsValid(_child);

  if (!this->_hasChild(_child))
  {
    this->children.push_front(_child);
    added = true;
  }

  return added;
}

bool ls::XmlNode::addChildToEnd(const ::std::shared_ptr<ls::XmlNode> &_child)
{
  bool added{};
  _checkIfNodeReferenceIsValid(_child);

  if (!this->_hasChild(_child))
  {
    this->children.push_back(_child);
    added = true;
  }

  return added;
}

void ls::XmlNode::clearValue()
{
  this->value.clear();
}

std::list<std::shared_ptr<ls::XmlAttribute>> ls::XmlNode::getAttributes()
{
  return this->attributes;
}

std::list<std::shared_ptr<ls::XmlNode>> ls::XmlNode::getChildren()
{
  return this->children;
}

std::list<std::shared_ptr<ls::XmlNode>> ls::XmlNode::getChildren(const ::std::string &_name)
{
  ::std::list<::std::shared_ptr<ls::XmlNode>> childrenWithName{};

  for (const auto &child : this->children)
  {
    if (child->getName() == _name)
    {
      childrenWithName.push_back(child);
    }
  }

  return childrenWithName;
}

std::string ls::XmlNode::getName()
{
  return this->name;
}

std::string ls::XmlNode::getValue()
{
  return this->value;
}

bool ls::XmlNode::hasAttribute(const ::std::string &_name)
{
  return this->_hasAttribute(_name);
}

bool ls::XmlNode::hasChild(const ::std::string &_name)
{
  return this->_hasChild(_name);
}

bool ls::XmlNode::hasChild(const ::std::shared_ptr<ls::XmlNode> &_child)
{
  return this->_hasChild(_child);
}

bool ls::XmlNode::removeFirstAttribute()
{
  bool isValidOperation = !this->attributes.empty();

  if (isValidOperation)
  {
    this->attributes.pop_front();
  }

  return isValidOperation;
}

bool ls::XmlNode::removeLastAttribute()
{
  bool isValidOperation = !this->attributes.empty();

  if (isValidOperation)
  {
    this->attributes.pop_back();
  }

  return isValidOperation;
}

bool ls::XmlNode::removeFirstChild()
{
  bool isValidOperation = !this->children.empty();

  if (isValidOperation)
  {
    this->children.pop_front();
  }

  return isValidOperation;
}

bool ls::XmlNode::removeLastChild()
{
  bool isValidOperation = !this->children.empty();

  if (isValidOperation)
  {
    this->children.pop_back();
  }

  return isValidOperation;
}

void ls::XmlNode::setName(const ::std::string &_name)
{
  this->_assignName(_name);
}

void ls::XmlNode::setValue(const ::std::string &_value)
{
  this->_assignValue(_value);
}

std::string ls::XmlNode::toXml()
{
  return this->_toXml_(0);
}

std::string ls::XmlNode::_toXml_(uint8_t _tabSize)
{
  ::std::string xmlStream{};

  xmlStream += ls::XmlNode::_getTab(_tabSize);
  xmlStream += this->_toXmlOpenTag();
  xmlStream += this->_toXmlAttributes();
  xmlStream += this->_toXmlOpenTagClose();
  xmlStream += this->_toXmlValue();
  xmlStream += this->_toXmlChildren(_tabSize + TAB_SIZE);
  xmlStream += this->value.empty() ? ls::XmlNode::_getTab(_tabSize) : "";
  xmlStream += this->_toXmlCloseTag() + "\n";

  return xmlStream;
}

void ls::XmlNode::_assignName(const ::std::string &_name)
{
  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->name = _name;
}

void ls::XmlNode::_assignValue(const ::std::string &_value)
{
  if (_value.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls::XmlNode::_checkIfAttributeReferenceIsValid(const ::std::shared_ptr<ls::XmlAttribute> &_attribute)
{
  if (_attribute == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
}

void ls::XmlNode::_checkIfNameIsNotEmpty(const ::std::string &_name)
{
  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }
}

void ls::XmlNode::_checkIfNodeReferenceIsValid(const ::std::shared_ptr<ls::XmlNode> &_child)
{
  if (_child == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }
}

std::string ls::XmlNode::_getTab(uint8_t _tabSize)
{
  ::std::string tab{};

  for (uint8_t index = 0; index < _tabSize; index++)
  {
    tab += " ";
  }

  return tab;
}

bool ls::XmlNode::_hasAttribute(const ::std::string &_name)
{
  bool exists{};

  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    for (const auto &attribute : this->attributes)
    {
      if (attribute->getName() == _name)
      {
        exists = true;
        break;
      }
    }
  }

  return exists;
}

bool ls::XmlNode::_hasChild(const ::std::shared_ptr<ls::XmlNode> &_child)
{
  _checkIfNodeReferenceIsValid(_child);
  return ls::std::core::STLUtils::contains(this->children, _child);
}

bool ls::XmlNode::_hasChild(const ::std::string &_name)
{
  bool exists{};

  if (_name.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }
  else
  {
    for (const auto &attribute : this->children)
    {
      if (attribute->getName() == _name)
      {
        exists = true;
        break;
      }
    }
  }

  return exists;
}

std::string ls::XmlNode::_toXmlAttributes()
{
  ::std::string stream{};

  for (const auto &_attribute : this->attributes)
  {
    stream += " " + _attribute->toXml();
  }

  return stream;
}

std::string ls::XmlNode::_toXmlChildren(uint8_t _tabSize)
{
  ::std::string stream{};

  if (this->value.empty())
  {
    for (const auto &_child : this->children)
    {
      stream += _child->_toXml_(_tabSize);
    }
  }

  return stream;
}

std::string ls::XmlNode::_toXmlCloseTag()
{
  ::std::string stream{};

  if (!this->children.empty() || !this->value.empty())
  {
    stream = "</" + this->name + ">";
  }

  return stream;
}

std::string ls::XmlNode::_toXmlOpenTag()
{
  return "<" + this->name;
}

std::string ls::XmlNode::_toXmlOpenTagClose()
{
  ::std::string stream{};

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

std::string ls::XmlNode::_toXmlValue()
{
  return this->value.empty() ? "\n" : this->value;
}
