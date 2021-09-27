/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2021-07-16
 *
 * */

#ifndef LS_STD_XML_DOCUMENT_HPP
#define LS_STD_XML_DOCUMENT_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "XmlNode.hpp"
#include "XmlDeclaration.hpp"

namespace ls_std
{
  class XmlDocument : public ls_std::Class
  {
    public:

      XmlDocument();
      ~XmlDocument() override = default;

      std::shared_ptr<ls_std::XmlDeclaration> getDeclaration();
      std::shared_ptr<ls_std::XmlNode> getRootElement();
      void setDeclaration(const std::shared_ptr<ls_std::XmlDeclaration> &_declaration);
      void setRootElement(const std::shared_ptr<ls_std::XmlNode> &_rootElement);
      std::string toXml();

    private:

      std::shared_ptr<ls_std::XmlDeclaration> declaration{};
      std::shared_ptr<ls_std::XmlNode> rootElement{};

      void _assignDeclaration(const std::shared_ptr<ls_std::XmlDeclaration> &_declaration);
      void _assignRootElement(const std::shared_ptr<ls_std::XmlNode> &_rootElement);
  };
}

#endif
