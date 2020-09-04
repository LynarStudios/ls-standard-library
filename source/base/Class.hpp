/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-09-04
 *
 * */

#ifndef LS_STD_CLASS_HPP
#define LS_STD_CLASS_HPP

#include <string>

namespace ls_std {
  class Class {
    public:

      explicit Class(std::string _name);
      ~Class() = default;

      std::string getClassName();

    private:

      std::string name {};
  };
}

#endif
