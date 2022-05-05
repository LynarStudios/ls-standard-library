/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_XML_DOCUMENT_HPP
#define LS_STD_XML_DOCUMENT_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "XmlNode.hpp"
#include "XmlDeclaration.hpp"

namespace ls
{
  class XmlDocument : public ls::Class
  {
    public:

      XmlDocument();
      ~XmlDocument() override = default;

      std::shared_ptr<ls::XmlDeclaration> getDeclaration();
      std::shared_ptr<ls::XmlNode> getRootElement();
      void setDeclaration(const std::shared_ptr<ls::XmlDeclaration> &_declaration);
      void setRootElement(const std::shared_ptr<ls::XmlNode> &_rootElement);
      std::string toXml();

    private:

      std::shared_ptr<ls::XmlDeclaration> declaration{};
      std::shared_ptr<ls::XmlNode> rootElement{};

      void _assignDeclaration(const std::shared_ptr<ls::XmlDeclaration> &_declaration);
      void _assignRootElement(const std::shared_ptr<ls::XmlNode> &_rootElement);
  };
}

#endif
