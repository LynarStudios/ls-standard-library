/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-15
*
* */

#ifndef LS_STD_SECTION_PAIR_SECTION_ID_UNMARSHAL_VALIDATOR_HPP
#define LS_STD_SECTION_PAIR_SECTION_ID_UNMARSHAL_VALIDATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IValidator.hpp>
#include <ls-std/core/type/Types.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairSectionIdUnmarshalValidator : public ls::std::core::Class, public ls::std::core::interface_type::IValidator
  {
    public:

      explicit SectionPairSectionIdUnmarshalValidator(ls::std::core::type::byte_field _data);
      ~SectionPairSectionIdUnmarshalValidator() override;

      [[nodiscard]] bool isValid() override;

    private:

      ls::std::core::type::byte_field data{};

      [[nodiscard]] static bool _isValidSection(const ls::std::core::type::byte_field &_bracketsNotation);
      [[nodiscard]] static ls::std::core::type::byte_field _trimStartAndEnd(const ls::std::core::type::byte_field &_trimmedWord, const ls::std::core::type::byte_field &_beginningTrimWord, const ls::std::core::type::byte_field &_endingTrimWord);
  };
}

#endif
