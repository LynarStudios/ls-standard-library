/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-24
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_XML_NODE_HPP
#define LS_STD_XML_NODE_HPP

#include <list>
#include <memory>
#include <ls_std/core/Class.hpp>
#include "XmlAttribute.hpp"

namespace ls
{
  namespace std
  {
    namespace io
    {
      class XmlNode : public ls::std::core::Class
      {
        public:

          explicit XmlNode(::std::string _name);
          ~XmlNode() override = default;

          bool addAttributeAfter(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute, const ::std::string &_name);
          bool addAttributeBefore(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute, const ::std::string &_name);
          bool addAttributeToBeginning(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute);
          bool addAttributeToEnd(const ::std::shared_ptr<ls::std::io::XmlAttribute> &_attribute);
          bool addChildAfter(const ::std::shared_ptr<ls::std::io::XmlNode> &_child, const ::std::shared_ptr<ls::std::io::XmlNode> &_search);
          bool addChildBefore(const ::std::shared_ptr<ls::std::io::XmlNode> &_child, const ::std::shared_ptr<ls::std::io::XmlNode> &_search);
          bool addChildToBeginning(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
          bool addChildToEnd(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
          void clearValue();
          ::std::list<::std::shared_ptr<ls::std::io::XmlAttribute>> getAttributes();
          ::std::list<::std::shared_ptr<ls::std::io::XmlNode>> getChildren();
          ::std::list<::std::shared_ptr<ls::std::io::XmlNode>> getChildren(const ::std::string &_name);
          ::std::string getName();
          ::std::string getValue();
          bool hasAttribute(const ::std::string &_name);
          bool hasChild(const ::std::string &_name);
          bool hasChild(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
          bool removeFirstAttribute();
          bool removeLastAttribute();
          bool removeFirstChild();
          bool removeLastChild();
          void setName(const ::std::string &_name);
          void setValue(const ::std::string &_value);
          ::std::string toXml();

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
          static ::std::string _getTab(uint8_t _tabSize);
          bool _hasAttribute(const ::std::string &_name);
          bool _hasChild(const ::std::shared_ptr<ls::std::io::XmlNode> &_child);
          bool _hasChild(const ::std::string &_name);
          ::std::string _toXmlAttributes();
          ::std::string _toXmlChildren(uint8_t _tabSize);
          ::std::string _toXmlCloseTag();
          ::std::string _toXmlOpenTag();
          ::std::string _toXmlOpenTagClose();
          ::std::string _toXmlValue();
      };
    }
  }
}

#endif
