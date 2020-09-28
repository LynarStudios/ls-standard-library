/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2020-09-27
 *
 * */

#ifndef LS_STD_XML_DOCUMENT_HPP
#define LS_STD_XML_DOCUMENT_HPP

#include <memory>
#include "../../base/Class.hpp"
#include "XMLNode.hpp"

namespace ls_std {
  class XMLDocument : public Class {
    public:

      XMLDocument();
      ~XMLDocument() = default;

      std::string getHeader();
      std::shared_ptr<ls_std::XMLNode> getRootElement();
      void parse(const std::string& _xmlStream);
      void setRootElement(const std::shared_ptr<ls_std::XMLNode>& _root);
      std::string toXML();

    private:

      std::string header {};
      std::shared_ptr<ls_std::XMLNode> rootElement {};

      std::string _getHeader();
  };
}

#endif
