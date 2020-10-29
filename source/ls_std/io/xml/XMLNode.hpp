/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2020-10-29
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
      void clearValue();
      std::list<std::shared_ptr<XMLAttribute>> getAttributes();
      std::list<std::shared_ptr<XMLNode>> getChildren();
      std::list<std::shared_ptr<XMLNode>> getChildren(const std::string& _name);
      std::string getName();
      std::string getValue();
      bool hasAttribute(const std::string& _name);
      bool hasChild(const std::string& _name);
      bool hasChild(const std::shared_ptr<XMLNode>& _child);
      void removeFirstAttribute();
      void removeLastAttribute();
      void removeFirstChild();
      void removeLastChild();
      void setName(std::string _name);
      void setValue(std::string _value);
      std::string toXML();

    protected:

      std::string _toXML_(uint8_t _tabSize);

    private:

      std::list<std::shared_ptr<XMLAttribute>> attributes {};
      std::list<std::shared_ptr<XMLNode>> children {};
      std::string name {};
      const static uint8_t TAB_SIZE {4};
      std::string value {};

      static std::string _getTab(uint8_t _tabSize);
      bool _hasAttribute(const std::string& _name);
      bool _hasChild(const std::shared_ptr<XMLNode>& _child);
      bool _hasChild(const std::string& _name);
      std::string _toXMLAttributes();
      std::string _toXMLChildren(uint8_t _tabSize);
      std::string _toXMLCloseTag();
      std::string _toXMLOpenTag();
      std::string _toXMLOpenTagClose();
      std::string _toXMLValue();
  };
}

#endif
