/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_XML_NODE_HPP
#define LS_STD_XML_NODE_HPP

#include <list>
#include <memory>
#include <ls_std/base/Class.hpp>
#include "XmlAttribute.hpp"

namespace ls_std
{
  class XmlNode : public ls_std::Class
  {
    public:

      explicit XmlNode(std::string _name);
      ~XmlNode() override = default;

      bool addAttributeAfter(const std::shared_ptr<ls_std::XmlAttribute> &_attribute, const std::string &_name);
      bool addAttributeBefore(const std::shared_ptr<ls_std::XmlAttribute> &_attribute, const std::string &_name);
      bool addAttributeToBeginning(const std::shared_ptr<ls_std::XmlAttribute> &_attribute);
      bool addAttributeToEnd(const std::shared_ptr<ls_std::XmlAttribute> &_attribute);
      bool addChildAfter(const std::shared_ptr<ls_std::XmlNode> &_child, const std::shared_ptr<ls_std::XmlNode> &_search);
      bool addChildBefore(const std::shared_ptr<ls_std::XmlNode> &_child, const std::shared_ptr<ls_std::XmlNode> &_search);
      bool addChildToBeginning(const std::shared_ptr<ls_std::XmlNode> &_child);
      bool addChildToEnd(const std::shared_ptr<ls_std::XmlNode> &_child);
      void clearValue();
      std::list<std::shared_ptr<ls_std::XmlAttribute>> getAttributes();
      std::list<std::shared_ptr<ls_std::XmlNode>> getChildren();
      std::list<std::shared_ptr<ls_std::XmlNode>> getChildren(const std::string &_name);
      std::string getName();
      std::string getValue();
      bool hasAttribute(const std::string &_name);
      bool hasChild(const std::string &_name);
      bool hasChild(const std::shared_ptr<ls_std::XmlNode> &_child);
      void removeFirstAttribute();
      void removeLastAttribute();
      void removeFirstChild();
      void removeLastChild();
      void setName(std::string _name);
      void setValue(std::string _value);
      std::string toXml();

    protected:

      std::string _toXml_(uint8_t _tabSize);

    private:

      std::list<std::shared_ptr<ls_std::XmlAttribute>> attributes{};
      std::list<std::shared_ptr<ls_std::XmlNode>> children{};
      std::string name{};
      const static uint8_t TAB_SIZE{4};
      std::string value{};

      static std::string _getTab(uint8_t _tabSize);
      bool _hasAttribute(const std::string &_name);
      bool _hasChild(const std::shared_ptr<ls_std::XmlNode> &_child);
      bool _hasChild(const std::string &_name);
      std::string _toXmlAttributes();
      std::string _toXmlChildren(uint8_t _tabSize);
      std::string _toXmlCloseTag();
      std::string _toXmlOpenTag();
      std::string _toXmlOpenTagClose();
      std::string _toXmlValue();
  };
}

#endif
