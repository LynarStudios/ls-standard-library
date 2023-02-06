/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_XML_NODE_HPP
#define LS_STD_XML_NODE_HPP

#include "XmlAttribute.hpp"
#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlNode : public ls::std::core::Class
  {
    public:

      explicit XmlNode(::std::string _name);
      ~XmlNode() override;

      bool addAttributeAfter(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute, const ::std::string &_name); // nodiscard is optional here
      bool addAttributeBefore(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute, const ::std::string &_name); // nodiscard is optional here
      bool addAttributeToBeginning(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute); // nodiscard is optional here
      bool addAttributeToEnd(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute); // nodiscard is optional here
      bool addChildAfter(const ::std::shared_ptr<ls::std::io::XmlNode> &_child, const ::std::shared_ptr<ls::std::io::XmlNode> &_search); // nodiscard is optional here
      bool addChildBefore(const ::std::shared_ptr<ls::std::io::XmlNode> &_child, const ::std::shared_ptr<ls::std::io::XmlNode> &_search); // nodiscard is optional here
      bool addChildToBeginning(const ::std::shared_ptr<ls::std::io::XmlNode> &_child); // nodiscard is optional here
      bool addChildToEnd(const ::std::shared_ptr<ls::std::io::XmlNode> &_child); // nodiscard is optional here
      void clearValue();
      [[nodiscard]] ::std::list<::std::shared_ptr<ls::std::io::XmlAttribute>> getAttributes();
      [[nodiscard]] ::std::list<::std::shared_ptr<ls::std::io::XmlNode>> getChildren();
      [[nodiscard]] ::std::list<::std::shared_ptr<ls::std::io::XmlNode>> getChildren(const ::std::string &_name);
      [[nodiscard]] ::std::string getName();
      [[nodiscard]] ::std::string getValue();
      [[nodiscard]] bool hasAttribute(const ::std::string &_name);
      [[nodiscard]] bool hasChild(const ::std::string &_name);
      [[nodiscard]] bool hasChild(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
      bool removeFirstAttribute(); // nodiscard is optional here
      bool removeLastAttribute(); // nodiscard is optional here
      bool removeFirstChild(); // nodiscard is optional here
      bool removeLastChild(); // nodiscard is optional here
      void setName(const ::std::string &_name);
      void setValue(const ::std::string &_value);
      [[nodiscard]] ::std::string toXml();

    protected:

      ::std::string _toXml_(uint8_t _tabSize);

    private:

      ::std::list<::std::shared_ptr<ls::std::io::XmlAttribute>> attributes{};
      ::std::list<::std::shared_ptr<ls::std::io::XmlNode>> children{};
      ::std::string name{};
      const static uint8_t TAB_SIZE{4};
      ::std::string value{};

      void _assignName(const ::std::string &_name);
      void _assignValue(const ::std::string &_value);
      static void _checkIfAttributeReferenceIsValid(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute);
      static void _checkIfNameIsNotEmpty(const ::std::string &_name);
      static void _checkIfNodeReferenceIsValid(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
      [[nodiscard]] static ::std::string _getTab(uint8_t _tabSize);
      [[nodiscard]] bool _hasAttribute(const ::std::string &_name);
      [[nodiscard]] bool _hasChild(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
      [[nodiscard]] bool _hasChild(const ::std::string &_name);
      [[nodiscard]] ::std::string _toXmlAttributes();
      [[nodiscard]] ::std::string _toXmlChildren(uint8_t _tabSize);
      [[nodiscard]] ::std::string _toXmlCloseTag();
      [[nodiscard]] ::std::string _toXmlOpenTag();
      [[nodiscard]] ::std::string _toXmlOpenTagClose();
      [[nodiscard]] ::std::string _toXmlValue();
  };
}

#endif
