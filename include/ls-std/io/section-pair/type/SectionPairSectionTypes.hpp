/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-13
*
* */

#ifndef LS_STD_SECTION_PAIR_SECTION_TYPES_HPP
#define LS_STD_SECTION_PAIR_SECTION_TYPES_HPP

#include <list>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <memory>

namespace ls::std::io
{
  using section_pair_row_list_element = ::std::shared_ptr<ls::std::io::SectionPairRow>;
  using section_pair_row_list = ::std::list<ls::std::io::section_pair_row_list_element>;
}

#endif
