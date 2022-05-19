/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-05-19
 *
 * */

#ifndef LS_STD_I_ENCODING_HPP
#define LS_STD_I_ENCODING_HPP

#include <string>

namespace ls
{
  namespace std
  {
    namespace core
    {
      namespace interface_type
      {
        class IEncoding
        {
          public:

            virtual ::std::string encode(const ::std::string &_sequence) = 0;
            virtual ::std::string decode(const ::std::string &_sequence) = 0;
        };
      }
    }
  }
}

#endif
