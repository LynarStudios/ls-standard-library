/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_XML_DECLARATION_HPP
#define LS_STD_XML_DECLARATION_HPP

#include "XmlAttribute.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlDeclaration : public ls::std::core::Class
  {
    public:

      explicit XmlDeclaration(const ::std::string &_version);
      ~XmlDeclaration() override;

      ::std::string getEncoding();
      ::std::string getStandalone();
      ::std::string getVersion();
      void setEncoding(const ::std::string &_encoding);
      void setStandalone(const ::std::string &_standalone);
      void setVersion(const ::std::string &_version);
      ::std::string toXml();

    private:

      ls::std::io::XmlAttribute encoding{"encoding"};
      ls::std::io::XmlAttribute standalone{"standalone"};
      ls::std::io::XmlAttribute version{"version"};

      static ::std::string _toXmlAttribute(ls::std::io::XmlAttribute _attribute);
  };
}

#endif
