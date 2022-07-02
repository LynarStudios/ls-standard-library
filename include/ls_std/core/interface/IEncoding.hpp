/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_I_ENCODING_HPP
#define LS_STD_I_ENCODING_HPP

#include <string>

namespace ls::std::core::interface_type
{
  class IEncoding
  {
    public:

      virtual ::std::string encode(const ::std::string &_sequence) = 0;
      virtual ::std::string decode(const ::std::string &_sequence) = 0;
  };
}

#endif
