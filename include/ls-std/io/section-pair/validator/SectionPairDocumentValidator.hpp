/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_DOCUMENT_VALIDATOR_HPP
#define LS_STD_SECTION_PAIR_DOCUMENT_VALIDATOR_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IValidator.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairDocumentValidator : public ls::std::core::Class, public ls::std::core::interface_type::IValidator
  {
    public:

      explicit SectionPairDocumentValidator(::std::string _document);
      ~SectionPairDocumentValidator() noexcept override;

      [[nodiscard]] bool isValid() override;

    private:

      ::std::string document{};

      [[nodiscard]] static ::std::string _getValidationRegex();
  };
}

#endif
