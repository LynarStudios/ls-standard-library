/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-10
*
* */

#ifndef LS_STD_SECTION_PAIR_ROW_VALUE_VALIDATOR_HPP
#define LS_STD_SECTION_PAIR_ROW_VALUE_VALIDATOR_HPP

#include "SectionPairTypes.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IValidator.hpp>
#include <string>

namespace ls::std::io
{
  class SectionPairRowValueValidator : public ls::std::core::Class, public ls::std::core::interface_type::IValidator
  {
    public:

      explicit SectionPairRowValueValidator(ls::std::io::section_pair_row_value _value);
      ~SectionPairRowValueValidator() override;

      bool isValid() override;

    private:

      ls::std::io::section_pair_row_value value{};
  };
}

#endif
