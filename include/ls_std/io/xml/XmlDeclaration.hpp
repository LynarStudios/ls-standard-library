/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_XML_DECLARATION_HPP
#define LS_STD_XML_DECLARATION_HPP

#include <ls_std/core/Class.hpp>
#include "XmlAttribute.hpp"

namespace ls
{
  class XmlDeclaration : public ls::Class
  {
    public:

      explicit XmlDeclaration(const ::std::string& _version);
      ~XmlDeclaration() override = default;

      ::std::string getEncoding();
      ::std::string getStandalone();
      ::std::string getVersion();
      void setEncoding(const ::std::string& _encoding);
      void setStandalone(const ::std::string& _standalone);
      void setVersion(const ::std::string& _version);
      ::std::string toXml();

    private:

      ls::XmlAttribute encoding{"encoding"};
      ls::XmlAttribute standalone{"standalone"};
      ls::XmlAttribute version{"version"};

      static ::std::string _toXmlAttribute(ls::XmlAttribute _attribute);
  };
}

#endif
