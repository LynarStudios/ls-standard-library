/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2020-09-26
 *
 * */

#ifndef LS_STD_XML_ATTRIBUTE_HPP
#define LS_STD_XML_ATTRIBUTE_HPP

#include "../../base/Class.hpp"
#include <string>

namespace ls_std {
  class XMLAttribute : public Class {
    public:

      explicit XMLAttribute(std::string _name);
      ~XMLAttribute() = default;

      std::string getName();
      std::string getValue();
      void setName(std::string _name);
      void setValue(std::string _value);
      std::string toXML();

    private:

      std::string name {};
      std::string value {};
  };
}

#endif
