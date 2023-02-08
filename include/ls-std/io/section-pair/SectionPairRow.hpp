/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_HPP
#define LS_STD_SECTION_PAIR_ROW_HPP

#include "SectionPairRowEnumType.hpp"
#include <list>
#include <ls-std/core/Class.hpp>
#include <string>

namespace ls::std::io
{
  class SectionPairRow : public ls::std::core::Class
  {
    public:

      explicit SectionPairRow(const ::std::string &_key);
      ~SectionPairRow() override;

      [[nodiscard]] ::std::string getValue();
      [[nodiscard]] bool isKeyValue();
      [[nodiscard]] bool isList();
      void setValue(const ::std::string &_value);

    private:

      ::std::string key{};
      ls::std::io::SectionPairRowEnumType type{};
      ::std::list<::std::string> values{};
  };
}

#endif
