/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2020-09-26
 *
 * */

#include "XMLNode.hpp"
#include "../../utils/STLUtils.hpp"

ls_std::XMLNode::XMLNode(std::string _name) : Class("XMLNode"),
name(std::move(_name))
{}

bool ls_std::XMLNode::addAttributeAfter(const std::shared_ptr<ls_std::XMLAttribute> &_attribute, const std::string &_name) {
  bool added {};
  auto iterator = this->attributes.begin();

  if(!this->_hasAttribute(_attribute->getName())) {
    while(iterator != this->attributes.end()) {
      if((*iterator)->getName() == _name) {
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

bool ls_std::XMLNode::addAttributeBefore(const std::shared_ptr<ls_std::XMLAttribute> &_attribute, const std::string &_name) {
  bool added {};
  auto iterator = this->attributes.begin();

  if(!this->_hasAttribute(_attribute->getName())) {
    while(iterator != this->attributes.end()) {
      if((*iterator)->getName() == _name) {
        this->attributes.insert(iterator, _attribute);
        added = true;
        break;
      }

      iterator++;
    }
  }

  return added;
}

bool ls_std::XMLNode::addAttributeToBeginning(const std::shared_ptr<ls_std::XMLAttribute> &_attribute)
{
  bool added {};

  if(_attribute != nullptr && !_hasAttribute(_attribute->getName())) {
    this->attributes.push_front(_attribute);
    added = true;
  }

  return added;
}

bool ls_std::XMLNode::addAttributeToEnd(const std::shared_ptr<ls_std::XMLAttribute> &_attribute)
{
  bool added {};

  if(_attribute != nullptr && !_hasAttribute(_attribute->getName())) {
    this->attributes.push_back(_attribute);
    added = true;
  }

  return added;
}

bool ls_std::XMLNode::addChildAfter(const std::shared_ptr<ls_std::XMLNode>& _child, const std::shared_ptr<ls_std::XMLNode>& _search)
{
  bool added {};
  auto iterator = this->children.begin();

  if(_child != nullptr && !this->_hasChild(_child)) {
    while(iterator != this->children.end()) {
      if(*iterator == _search) {
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

bool ls_std::XMLNode::addChildBefore(const std::shared_ptr<ls_std::XMLNode>& _child, const std::shared_ptr<ls_std::XMLNode>& _search)
{
  bool added {};
  auto iterator = this->children.begin();

  if(_child != nullptr && !this->_hasChild(_child)) {
    while(iterator != this->children.end()) {
      if(*iterator == _search) {
        this->children.insert(iterator, _child);
        added = true;
        break;
      }

      iterator++;
    }
  }

  return added;
}

bool ls_std::XMLNode::addChildToBeginning(const std::shared_ptr<XMLNode> &_child)
{
  bool added {};

  if(_child != nullptr && !this->_hasChild(_child)) {
    this->children.push_front(_child);
    added = true;
  }

  return added;
}

bool ls_std::XMLNode::addChildToEnd(const std::shared_ptr<XMLNode>& _child)
{
  bool added {};

  if(_child != nullptr && !this->_hasChild(_child)) {
    this->children.push_back(_child);
    added = true;
  }

  return added;
}

void ls_std::XMLNode::clearValue()
{
  this->value.clear();
}

std::list<std::shared_ptr<ls_std::XMLAttribute>> ls_std::XMLNode::getAttributes()
{
  return this->attributes;
}

std::list<std::shared_ptr<ls_std::XMLNode>> ls_std::XMLNode::getChildren()
{
  return this->children;
}

std::list<std::shared_ptr<ls_std::XMLNode>> ls_std::XMLNode::getChildren(const std::string &_name)
{
  std::list<std::shared_ptr<ls_std::XMLNode>> childrenWithName {};

  for(const auto& child : this->children) {
    if(child->getName() == _name) {
      childrenWithName.push_back(child);
    }
  }

  return childrenWithName;
}

std::string ls_std::XMLNode::getName()
{
  return this->name;
}

std::string ls_std::XMLNode::getValue()
{
  return this->value;
}

bool ls_std::XMLNode::hasAttribute(const std::string &_name)
{
  return this->_hasAttribute(_name);
}

bool ls_std::XMLNode::hasChild(const std::string &_name)
{
  return this->_hasChild(_name);
}

bool ls_std::XMLNode::hasChild(const std::shared_ptr<XMLNode> &_child)
{
  return this->_hasChild(_child);
}

void ls_std::XMLNode::removeFirstAttribute()
{
  if(!this->attributes.empty()) {
    this->attributes.pop_front();
  }
}

void ls_std::XMLNode::removeLastAttribute()
{
  if(!this->attributes.empty()) {
    this->attributes.pop_back();
  }
}

void ls_std::XMLNode::removeFirstChild()
{
  if(!this->children.empty()) {
    this->children.pop_front();
  }
}

void ls_std::XMLNode::removeLastChild()
{
  if(!this->children.empty()) {
    this->children.pop_back();
  }
}

void ls_std::XMLNode::setName(std::string _name)
{
  this->name = std::move(_name);
}

void ls_std::XMLNode::setValue(std::string _value)
{
  this->value = std::move(_value);
}

std::string ls_std::XMLNode::toXML()
{
  std::string xmlStream {};

  xmlStream += this->_toXMLOpenTag();
  xmlStream += this->_toXMLAttributes();
  xmlStream += this->_toXMLOpenTagClose();
  xmlStream += this->value;
  xmlStream += this->_toXMLChildren();
  xmlStream += this->_toXMLCloseTag();

  return xmlStream;
}

bool ls_std::XMLNode::_hasAttribute(const std::string &_name)
{
  bool exists {};

  for(const auto& attribute : this->attributes) {
    if(attribute->getName() == _name) {
      exists = true;
      break;
    }
  }

  return exists;
}

bool ls_std::XMLNode::_hasChild(const std::shared_ptr<ls_std::XMLNode> &_child)
{
  return ls_std::STLUtils<std::list<std::shared_ptr<ls_std::XMLNode>>, std::shared_ptr<ls_std::XMLNode>>::contains(this->children, _child);
}

bool ls_std::XMLNode::_hasChild(const std::string &_name)
{
  bool exists {};

  for(const auto& attribute : this->children) {
    if(attribute->getName() == _name) {
      exists = true;
      break;
    }
  }

  return exists;
}

std::string ls_std::XMLNode::_toXMLAttributes()
{
  std::string stream {};

  for(const auto& _attribute : this->attributes) {
    stream += " " + _attribute->toXML();
  }

  return stream;
}

std::string ls_std::XMLNode::_toXMLChildren()
{
  std::string stream {};

  if(this->value.empty()) {
    for(const auto& _child : this->children) {
      stream += _child->toXML();
    }
  }

  return stream;
}

std::string ls_std::XMLNode::_toXMLCloseTag()
{
  std::string stream {};

  if(!this->children.empty() || !this->value.empty()) {
    stream = "</" + this->name + ">";
  }

  return stream;
}

std::string ls_std::XMLNode::_toXMLOpenTag()
{
  return "<" + this->name;
}

std::string ls_std::XMLNode::_toXMLOpenTagClose()
{
  std::string stream {};

  if(this->children.empty() && this->value.empty()) {
    stream = "/>";
  } else {
    stream = ">";
  }

  return stream;
}
