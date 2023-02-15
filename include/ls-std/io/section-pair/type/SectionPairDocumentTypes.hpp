/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-15
*
* */

#ifndef LS_STD_SECTION_PAIR_DOCUMENT_TYPES_HPP
#define LS_STD_SECTION_PAIR_DOCUMENT_TYPES_HPP

#include <list>
#include <ls-std/io/section-pair/model/SectionPairSection.hpp>
#include <memory>

namespace ls::std::io
{
  using section_pair_document_section_list_element = ::std::shared_ptr<ls::std::io::SectionPairSection>;
  using section_pair_document_section_list = ::std::list<ls::std::io::section_pair_document_section_list_element>;
}

#endif
