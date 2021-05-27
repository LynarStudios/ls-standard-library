/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_XML_DECLARATION_HPP
#define LS_STD_XML_DECLARATION_HPP

#include <ls_std/base/Class.hpp>
#include "XmlAttribute.hpp"

namespace ls_std
{
  class XmlDeclaration : public ls_std::Class
  {
    public:

      explicit XmlDeclaration(std::string _version);
      ~XmlDeclaration() override = default;

      std::string getEncoding();
      std::string getStandalone();
      std::string getVersion();
      void setEncoding(std::string _encoding);
      void setStandalone(std::string _standalone);
      void setVersion(std::string _version);
      std::string toXml();

    private:

      ls_std::XmlAttribute encoding{"encoding"};
      ls_std::XmlAttribute standalone{"standalone"};
      ls_std::XmlAttribute version{"version"};

      static std::string _toXmlAttribute(ls_std::XmlAttribute _attribute);
  };
}

#endif
