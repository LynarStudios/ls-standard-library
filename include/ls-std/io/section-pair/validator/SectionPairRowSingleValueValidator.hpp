/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-20
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_SINGLE_VALUE_VALIDATOR_HPP
#define LS_STD_SECTION_PAIR_ROW_SINGLE_VALUE_VALIDATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IValidator.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairRowSingleValueValidator : public ls::std::core::Class, public ls::std::core::interface_type::IValidator
  {
    public:

      explicit SectionPairRowSingleValueValidator(::std::string _singleValueRow);
      ~SectionPairRowSingleValueValidator() override;

      [[nodiscard]] static ::std::string getValidationRegex();
      [[nodiscard]] bool isValid() override;

    private:

      ::std::string singleValueRow{};

      [[nodiscard]] static ::std::string _getValidationRegex();
  };
}

#endif
