/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#ifndef LS_STD_SECTION_PAIR_FILE_EXTENSION_VALIDATOR_HPP
#define LS_STD_SECTION_PAIR_FILE_EXTENSION_VALIDATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IValidator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairFileExtensionValidator : public ls::std::core::Class, public ls::std::core::interface_type::IValidator
  {
    public:

      explicit SectionPairFileExtensionValidator(::std::string _fileName);
      ~SectionPairFileExtensionValidator() override;

      [[nodiscard]] bool isValid() override;

    private:

      ::std::string fileName{};
  };
}

#endif
