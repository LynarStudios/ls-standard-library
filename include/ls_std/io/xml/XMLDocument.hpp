/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_XML_DOCUMENT_HPP
#define LS_STD_XML_DOCUMENT_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "XMLNode.hpp"
#include "XMLDeclaration.hpp"

namespace ls_std
{
  class XMLDocument : public ls_std::Class
  {
    public:

      XMLDocument();
      ~XMLDocument() override = default;

      std::shared_ptr<ls_std::XMLDeclaration> getDeclaration();
      std::shared_ptr<ls_std::XMLNode> getRootElement();
      void setDeclaration(const std::shared_ptr<ls_std::XMLDeclaration> &_declaration);
      void setRootElement(const std::shared_ptr<ls_std::XMLNode> &_root);
      std::string toXML();

    private:

      std::shared_ptr<ls_std::XMLDeclaration> declaration{};
      std::shared_ptr<ls_std::XMLNode> rootElement{};
  };
}

#endif
