/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-17
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_PROVIDER_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_ROW_PROVIDER_HPP

#include <ls-std/ls-std-io.hpp>
#include <memory>
#include <string>

namespace test::io
{
  class SerializableSectionPairRowProvider
  {
    public:

      SerializableSectionPairRowProvider();
      ~SerializableSectionPairRowProvider();

      static ::std::shared_ptr<ls::std::io::SerializableSectionPairRow> createListValueForMarshal(const ::std::string &_newLine);
      static ::std::shared_ptr<ls::std::io::SerializableSectionPairRow> createListValueForUnmarshal(const ::std::string &_newLine);
      static ::std::shared_ptr<ls::std::io::SerializableSectionPairRow> createSingleValueForMarshal(const ::std::string &_newLine);
      static ::std::shared_ptr<ls::std::io::SerializableSectionPairRow> createSingleValueForUnmarshal(const ::std::string &_newLine);
  };
}

#endif
