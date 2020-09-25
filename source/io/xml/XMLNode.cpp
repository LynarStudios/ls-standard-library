/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2020-09-24
 *
 * */

#include "XMLNode.hpp"
#include "../../utils/STLUtils.hpp"

ls_std::XMLNode::XMLNode(std::string _name) : Class("XMLNode"),
name(std::move(_name))
{}

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
  this->attributes.pop_front();
}

void ls_std::XMLNode::removeLastAttribute()
{
  this->attributes.pop_back();
}

void ls_std::XMLNode::removeFirstChild()
{
  this->children.pop_front();
}

void ls_std::XMLNode::removeLastChild()
{
  this->children.pop_back();
}

void ls_std::XMLNode::setName(std::string _name)
{
  this->name = std::move(_name);
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
