/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-16
*
* */

#ifndef LS_STD_SECTION_PAIR_SECTION_PROVIDER_HPP
#define LS_STD_SECTION_PAIR_SECTION_PROVIDER_HPP

#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

namespace test::io
{
  class SectionPairSectionProvider
  {
    public:

      SectionPairSectionProvider();
      ~SectionPairSectionProvider();

      static ::std::shared_ptr<ls::std::io::SectionPairSection> createSectionWithSandraExample();
      static ::std::shared_ptr<ls::std::io::SectionPairSection> createSectionWithTomExample();
      static ls::std::core::type::byte_field createSerializedSectionWithSandraExample();
      static ls::std::core::type::byte_field createSerializedSectionWithTomExample();
  };
}

#endif
