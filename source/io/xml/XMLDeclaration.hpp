/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2020-09-27
 *
 * */

#ifndef LS_STD_XML_DECLARATION_HPP
#define LS_STD_XML_DECLARATION_HPP

#include "../../base/Class.hpp"

namespace ls_std {
  class XMLDeclaration : public Class {
    public:

      XMLDeclaration();
      ~XMLDeclaration() = default;

    private:

      std::string version {};
  };
}

#endif
