/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-09-04
 *
 * */

#ifndef LS_STD_STL_UTILS_HPP
#define LS_STD_STL_UTILS_HPP

#include <algorithm>

namespace ls_std {
  template<class container, class dataType>
  class STLUtils {
    public:

      STLUtils() = default;
      ~STLUtils() = default;

      static bool contains(container _container, const dataType& _value) {
        return std::find(_container.begin(), _container.end(), _value) != _container.end();
      }
  };
}

#endif
