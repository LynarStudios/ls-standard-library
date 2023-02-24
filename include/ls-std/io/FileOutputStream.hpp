/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_FILE_OUTPUT_STREAM_HPP
#define LS_STD_FILE_OUTPUT_STREAM_HPP

#include "File.hpp"
#include <fstream>
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IWriter.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL FileOutputStream : public ls::std::core::Class, public ls::std::core::interface_type::IWriter
  {
    public:

      explicit FileOutputStream(ls::std::io::File &_file);
      explicit FileOutputStream(ls::std::io::File &_file, bool _append);
      ~FileOutputStream() noexcept override;

      void close();
      bool write(const ls::std::core::type::byte_field &_data) override; // nodiscard is optional here

    private:

      bool append{};
      ls::std::io::File file;
      ::std::ofstream outputStream{};

      void _close();
      void _init();
  };
}

#endif
