/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_CLASS_HPP
#define LS_STD_CLASS_HPP

#include <string>

namespace ls
{
  namespace std
  {
    namespace core
    {
      class Class
      {
        public:

          explicit Class(const ::std::string &_name);
          virtual ~Class() = default;

          ::std::string getClassName();

        private:

          ::std::string name{};

          void _assignClassName(const ::std::string &_name);
      };
    }
  }
}

#endif
