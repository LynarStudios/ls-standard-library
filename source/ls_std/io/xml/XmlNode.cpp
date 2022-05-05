/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/xml/XmlNode.hpp>
#include <ls_std/core/utils/STLUtils.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls_std::XmlNode::XmlNode(std::string _name)
    : ls_std::Class("XmlNode"),
      name(std::move(_name))
{}

bool ls_std::XmlNode::addAttributeAfter(const std::shared_ptr<ls_std::XmlAttribute> &_attribute, const std::string &_name)
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

bool ls_std::XmlNode::addAttributeBefore(const std::shared_ptr<ls_std::XmlAttribute> &_attribute, const std::string &_name)
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

bool ls_std::XmlNode::addAttributeToBeginning(const std::shared_ptr<ls_std::XmlAttribute> &_attribute)
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

bool ls_std::XmlNode::addAttributeToEnd(const std::shared_ptr<ls_std::XmlAttribute> &_attribute)
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

bool ls_std::XmlNode::addChildAfter(const std::shared_ptr<ls_std::XmlNode> &_child, const std::shared_ptr<ls_std::XmlNode> &_search)
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

bool ls_std::XmlNode::addChildBefore(const std::shared_ptr<ls_std::XmlNode> &_child, const std::shared_ptr<ls_std::XmlNode> &_search)
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

bool ls_std::XmlNode::addChildToBeginning(const std::shared_ptr<ls_std::XmlNode> &_child)
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

bool ls_std::XmlNode::addChildToEnd(const std::shared_ptr<ls_std::XmlNode> &_child)
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

void ls_std::XmlNode::clearValue()
{
  this->value.clear();
}

std::list<std::shared_ptr<ls_std::XmlAttribute>> ls_std::XmlNode::getAttributes()
{
  return this->attributes;
}

std::list<std::shared_ptr<ls_std::XmlNode>> ls_std::XmlNode::getChildren()
{
  return this->children;
}

std::list<std::shared_ptr<ls_std::XmlNode>> ls_std::XmlNode::getChildren(const std::string &_name)
{
  std::list<std::shared_ptr<ls_std::XmlNode>> childrenWithName{};

  for (const auto &child : this->children)
  {
    if (child->getName() == _name)
    {
      childrenWithName.push_back(child);
    }
  }

  return childrenWithName;
}

std::string ls_std::XmlNode::getName()
{
  return this->name;
}

std::string ls_std::XmlNode::getValue()
{
  return this->value;
}

bool ls_std::XmlNode::hasAttribute(const std::string &_name)
{
  return this->_hasAttribute(_name);
}

bool ls_std::XmlNode::hasChild(const std::string &_name)
{
  return this->_hasChild(_name);
}

bool ls_std::XmlNode::hasChild(const std::shared_ptr<ls_std::XmlNode> &_child)
{
  return this->_hasChild(_child);
}

bool ls_std::XmlNode::removeFirstAttribute()
{
  bool isValidOperation = !this->attributes.empty();

  if (isValidOperation)
  {
    this->attributes.pop_front();
  }

  return isValidOperation;
}

bool ls_std::XmlNode::removeLastAttribute()
{
  bool isValidOperation = !this->attributes.empty();

  if (isValidOperation)
  {
    this->attributes.pop_back();
  }

  return isValidOperation;
}

bool ls_std::XmlNode::removeFirstChild()
{
  bool isValidOperation = !this->children.empty();

  if (isValidOperation)
  {
    this->children.pop_front();
  }

  return isValidOperation;
}

bool ls_std::XmlNode::removeLastChild()
{
  bool isValidOperation = !this->children.empty();

  if (isValidOperation)
  {
    this->children.pop_back();
  }

  return isValidOperation;
}

void ls_std::XmlNode::setName(const std::string &_name)
{
  this->_assignName(_name);
}

void ls_std::XmlNode::setValue(const std::string &_value)
{
  this->_assignValue(_value);
}

std::string ls_std::XmlNode::toXml()
{
  return this->_toXml_(0);
}

std::string ls_std::XmlNode::_toXml_(uint8_t _tabSize)
{
  std::string xmlStream{};

  xmlStream += ls_std::XmlNode::_getTab(_tabSize);
  xmlStream += this->_toXmlOpenTag();
  xmlStream += this->_toXmlAttributes();
  xmlStream += this->_toXmlOpenTagClose();
  xmlStream += this->_toXmlValue();
  xmlStream += this->_toXmlChildren(_tabSize + TAB_SIZE);
  xmlStream += this->value.empty() ? ls_std::XmlNode::_getTab(_tabSize) : "";
  xmlStream += this->_toXmlCloseTag() + "\n";

  return xmlStream;
}

void ls_std::XmlNode::_assignName(const std::string &_name)
{
  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->name = _name;
}

void ls_std::XmlNode::_assignValue(const std::string &_value)
{
  if (_value.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->value = _value;
}

void ls_std::XmlNode::_checkIfAttributeReferenceIsValid(const std::shared_ptr<ls_std::XmlAttribute> &_attribute)
{
  if (_attribute == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }
}

void ls_std::XmlNode::_checkIfNameIsNotEmpty(const std::string &_name)
{
  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }
}

void ls_std::XmlNode::_checkIfNodeReferenceIsValid(const std::shared_ptr<ls_std::XmlNode> &_child)
{
  if (_child == nullptr)
  {
    throw ls_std::IllegalArgumentException{};
  }
}

std::string ls_std::XmlNode::_getTab(uint8_t _tabSize)
{
  std::string tab{};

  for (uint8_t index = 0; index < _tabSize; index++)
  {
    tab += " ";
  }

  return tab;
}

bool ls_std::XmlNode::_hasAttribute(const std::string &_name)
{
  bool exists{};

  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
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

bool ls_std::XmlNode::_hasChild(const std::shared_ptr<ls_std::XmlNode> &_child)
{
  _checkIfNodeReferenceIsValid(_child);
  return ls_std::STLUtils::contains(this->children, _child);
}

bool ls_std::XmlNode::_hasChild(const std::string &_name)
{
  bool exists{};

  if (_name.empty())
  {
    throw ls_std::IllegalArgumentException{};
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

std::string ls_std::XmlNode::_toXmlAttributes()
{
  std::string stream{};

  for (const auto &_attribute : this->attributes)
  {
    stream += " " + _attribute->toXml();
  }

  return stream;
}

std::string ls_std::XmlNode::_toXmlChildren(uint8_t _tabSize)
{
  std::string stream{};

  if (this->value.empty())
  {
    for (const auto &_child : this->children)
    {
      stream += _child->_toXml_(_tabSize);
    }
  }

  return stream;
}

std::string ls_std::XmlNode::_toXmlCloseTag()
{
  std::string stream{};

  if (!this->children.empty() || !this->value.empty())
  {
    stream = "</" + this->name + ">";
  }

  return stream;
}

std::string ls_std::XmlNode::_toXmlOpenTag()
{
  return "<" + this->name;
}

std::string ls_std::XmlNode::_toXmlOpenTagClose()
{
  std::string stream{};

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

std::string ls_std::XmlNode::_toXmlValue()
{
  return this->value.empty() ? "\n" : this->value;
}
