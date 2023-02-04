/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_FILE_READER_HPP
#define LS_STD_FILE_READER_HPP

#include "File.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL FileReader : public ls::std::core::Class, public ls::std::core::interface_type::IReader
  {
    public:

      explicit FileReader(ls::std::io::File &_file);
      ~FileReader() override = default;

      ls::std::core::type::byte_field read() override;
      void reset(ls::std::io::File &_file);

    private:

      ls::std::io::File file;

      static void _init(ls::std::io::File &_file);
  };
}

#endif
