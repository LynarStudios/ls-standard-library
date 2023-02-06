/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-12-25
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_KV_PARSE_DATA_HPP
#define LS_STD_KV_PARSE_DATA_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL KvParseParameter
  {
    public:

      KvParseParameter();
      ~KvParseParameter();

      [[nodiscard]] ::std::string::size_type getIndex() const;
      [[nodiscard]] ::std::string getLine();
      void setIndex(const ::std::string::size_type &_index);
      void setLine(const ::std::string &_line);

    private:

      ::std::string::size_type index{};
      ::std::string line{};
  };
}

#endif
