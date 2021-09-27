/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_FILE_WRITER_HPP
#define LS_STD_FILE_WRITER_HPP

#include <ls_std/base/Class.hpp>
#include "IWriter.hpp"
#include "File.hpp"

namespace ls_std
{
  class FileWriter : public ls_std::Class, public ls_std::IWriter
  {
    public:

      explicit FileWriter(ls_std::File &_file);
      ~FileWriter() override = default;

      void reset(ls_std::File &_file);
      bool write(const ls_std::byte_field &_data) override;

    private:

      ls_std::File file;

      static void _init(ls_std::File &_file);
  };
}

#endif
