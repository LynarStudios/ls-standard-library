/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-17
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_PARAMETER_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_PARAMETER_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SerializableSectionPairParameter
  {
    public:

      SerializableSectionPairParameter();
      ~SerializableSectionPairParameter();

      [[nodiscard]] ::std::string getNewLine();
      [[nodiscard]] ::std::shared_ptr<ls::std::core::Class> getValue() const;
      void setNewLine(const ::std::string &_newLine);
      void setValue(const ::std::shared_ptr<ls::std::core::Class> &_value);

    private:

      ::std::string parseNewLine{};
      ::std::shared_ptr<ls::std::core::Class> value{};
  };
}

#endif
