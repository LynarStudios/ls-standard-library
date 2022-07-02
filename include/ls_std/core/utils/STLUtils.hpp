/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_STL_UTILS_HPP
#define LS_STD_STL_UTILS_HPP

#include <algorithm>
#include <list>

namespace ls::std::core
{
  class STLUtils
  {
    public:

      STLUtils() = default;
      ~STLUtils() = default;

      template<class container, class dataType>
      static bool contains(container _container, const dataType &_value)
      {
        return ::std::find(_container.begin(), _container.end(), _value) != _container.end();
      }

      template<class dataType>
      static dataType getListElementAt(const ::std::list<dataType> &_list, size_t _index)
      {
        dataType value{};
        size_t counter{};

        if (_index < _list.size())
        {
          for (const auto &_value: _list)
          {
            if (counter == _index)
            {
              value = _value;
              break;
            }

            counter++;
          }
        }

        return value;
      }
  };
}

#endif
