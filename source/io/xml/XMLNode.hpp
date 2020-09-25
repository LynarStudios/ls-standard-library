/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2020-09-25
 *
 * */

#ifndef LS_STD_XML_NODE_HPP
#define LS_STD_XML_NODE_HPP

#include <list>
#include <memory>
#include "../../base/Class.hpp"
#include "XMLAttribute.hpp"

namespace ls_std {
  class XMLNode : public Class {
    public:

      explicit XMLNode(std::string _name);
      ~XMLNode() = default;

      bool addAttributeAfter(const std::shared_ptr<ls_std::XMLAttribute>& _attribute, const std::string& _name);
      bool addAttributeBefore(const std::shared_ptr<ls_std::XMLAttribute>& _attribute, const std::string& _name);
      bool addAttributeToBeginning(const std::shared_ptr<ls_std::XMLAttribute>& _attribute);
      bool addAttributeToEnd(const std::shared_ptr<ls_std::XMLAttribute>& _attribute);
      bool addChildAfter(const std::shared_ptr<XMLNode>& _child, const std::shared_ptr<XMLNode>& _search);
      bool addChildBefore(const std::shared_ptr<XMLNode>& _child, const std::shared_ptr<XMLNode>& _search);
      bool addChildToBeginning(const std::shared_ptr<XMLNode>& _child);
      bool addChildToEnd(const std::shared_ptr<XMLNode>& _child);
      std::list<std::shared_ptr<XMLAttribute>> getAttributes();
      std::list<std::shared_ptr<XMLNode>> getChildren();
      std::list<std::shared_ptr<XMLNode>> getChildren(const std::string& _name);
      std::string getName();
      bool hasAttribute(const std::string& _name);
      bool hasChild(const std::string& _name);
      bool hasChild(const std::shared_ptr<XMLNode>& _child);
      void removeFirstAttribute();
      void removeLastAttribute();
      void removeFirstChild();
      void removeLastChild();
      void setName(std::string _name);
      std::string toXML();

    private:

      std::list<std::shared_ptr<XMLAttribute>> attributes {};
      std::list<std::shared_ptr<XMLNode>> children {};
      std::string name {};

      bool _hasAttribute(const std::string& _name);
      bool _hasChild(const std::shared_ptr<XMLNode>& _child);
      bool _hasChild(const std::string& _name);
  };
}

#endif
