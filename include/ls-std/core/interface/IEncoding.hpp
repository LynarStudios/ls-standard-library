/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_I_ENCODING_HPP
#define LS_STD_I_ENCODING_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::core::interface_type
{
  class LS_STD_DYNAMIC_GOAL IEncoding
  {
    public:

      IEncoding();
      virtual ~IEncoding();

      virtual ::std::string encode(const ::std::string &_sequence) = 0;
      virtual ::std::string decode(const ::std::string &_sequence) = 0;
  };
}

#endif
