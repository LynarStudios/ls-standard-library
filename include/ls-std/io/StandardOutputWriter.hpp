/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2023-02-04
 *
 * */

#ifndef LS_STD_STANDARD_OUTPUT_WRITER_HPP
#define LS_STD_STANDARD_OUTPUT_WRITER_HPP

#include <ls-std/core/interface/IWriter.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL StandardOutputWriter : public ls::std::core::interface_type::IWriter
  {
    public:

      StandardOutputWriter();
      ~StandardOutputWriter();

      bool write(const ls::std::core::type::byte_field &_data) override;
  };
}

#endif
