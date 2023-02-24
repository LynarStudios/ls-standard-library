/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_IDENTIFIER_VALIDATOR_HPP
#define LS_STD_SECTION_PAIR_IDENTIFIER_VALIDATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IValidator.hpp>
#include <ls-std/io/section-pair/SectionPairTypes.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairIdentifierValidator : public ls::std::core::Class, public ls::std::core::interface_type::IValidator
  {
    public:

      explicit SectionPairIdentifierValidator(ls::std::io::section_pair_identifier _identifier);
      ~SectionPairIdentifierValidator() noexcept override;

      [[nodiscard]] static ::std::string getValidationRegex();
      [[nodiscard]] bool isValid() override;

    private:

      ls::std::io::section_pair_identifier identifier{};

      [[nodiscard]] static ::std::string _getValidationRegex();
  };
}

#endif
