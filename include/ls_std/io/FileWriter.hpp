/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_FILE_WRITER_HPP
#define LS_STD_FILE_WRITER_HPP

#include <ls_std/core/Class.hpp>
#include "IWriter.hpp"
#include "File.hpp"

namespace ls
{
  class FileWriter : public ls::std::core::Class, public ls::IWriter
  {
    public:

      explicit FileWriter(ls::File &_file);
      ~FileWriter() override = default;

      void reset(ls::File &_file);
      bool write(const ls::std::core::byte_field &_data) override;

    private:

      ls::File file;

      static void _init(ls::File &_file);
  };
}

#endif
