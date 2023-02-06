/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_XML_DOCUMENT_HPP
#define LS_STD_XML_DOCUMENT_HPP

#include "XmlDeclaration.hpp"
#include "XmlNode.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlDocument : public ls::std::core::Class
  {
    public:

      XmlDocument();
      ~XmlDocument() override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::XmlDeclaration> getDeclaration();
      [[nodiscard]] ::std::shared_ptr<ls::std::io::XmlNode> getRootElement();
      void setDeclaration(const ::std::shared_ptr<ls::std::io::XmlDeclaration> &_declaration);
      void setRootElement(const ::std::shared_ptr<ls::std::io::XmlNode> &_rootElement);
      [[nodiscard]] ::std::string toXml();

    private:

      ::std::shared_ptr<ls::std::io::XmlDeclaration> declaration{};
      ::std::shared_ptr<ls::std::io::XmlNode> rootElement{};

      void _assignDeclaration(const ::std::shared_ptr<ls::std::io::XmlDeclaration> &_declaration);
      void _assignRootElement(const ::std::shared_ptr<ls::std::io::XmlNode> &_rootElement);
  };
}

#endif
