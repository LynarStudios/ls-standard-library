/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-20
*
* */

#ifndef LS_STD_SECTION_PAIR_SECTION_PROVIDER_HPP
#define LS_STD_SECTION_PAIR_SECTION_PROVIDER_HPP

#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>
#include <string>

namespace test::io
{
  class SectionPairSectionProvider
  {
    public:

      SectionPairSectionProvider();
      ~SectionPairSectionProvider();

      [[nodiscard]] static ::std::shared_ptr<ls::std::io::SectionPairSection> createSectionWithSandraExample();
      [[nodiscard]] static ::std::shared_ptr<ls::std::io::SectionPairSection> createSectionWithTomExample();
      [[nodiscard]] static ls::std::core::type::byte_field createSerializedSectionWithSandraExample(const ::std::string &_newLine);
      [[nodiscard]] static ls::std::core::type::byte_field createSerializedSectionWithTomExample(const ::std::string &_newLine);
  };
}

#endif
