/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2020-11-20
 *
 * */

#ifndef LS_STD_XML_DECLARATION_HPP
#define LS_STD_XML_DECLARATION_HPP

#include <ls_std/base/Class.hpp>
#include "XMLAttribute.hpp"

namespace ls_std {
  class XMLDeclaration : public Class {
    public:

      explicit XMLDeclaration(std::string _version);
      ~XMLDeclaration() = default;

      std::string getEncoding();
      std::string getStandalone();
      std::string getVersion();
      void setEncoding(std::string _encoding);
      void setStandalone(std::string _standalone);
      void setVersion(std::string _version);
      std::string toXML();

    private:

      ls_std::XMLAttribute encoding {"encoding"};
      ls_std::XMLAttribute standalone {"standalone"};
      ls_std::XMLAttribute version {"version"};

      static std::string _toXMLAttribute(XMLAttribute _attribute);
  };
}

#endif
