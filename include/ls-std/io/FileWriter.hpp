/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_FILE_WRITER_HPP
#define LS_STD_FILE_WRITER_HPP

#include "File.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IWriter.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL FileWriter : public ls::std::core::Class, public ls::std::core::interface_type::IWriter
  {
    public:

      explicit FileWriter(ls::std::io::File &_file);
      ~FileWriter() override;

      void reset(ls::std::io::File &_file);
      bool write(const ls::std::core::type::byte_field &_data) override; // nodiscard is optional here

    private:

      ls::std::io::File file;

      static void _init(ls::std::io::File &_file);
  };
}

#endif
