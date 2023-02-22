/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-22
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SECTION_PAIR_MESSAGE_FORMATTER_HPP
#define LS_STD_SECTION_PAIR_MESSAGE_FORMATTER_HPP

#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SectionPairMessageFormatter
  {
    public:

      SectionPairMessageFormatter();
      ~SectionPairMessageFormatter();

      [[nodiscard]] static ::std::string getFormattedMessage(const ::std::string &_message);
  };
}

#endif
