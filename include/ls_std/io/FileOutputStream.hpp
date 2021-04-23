/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_FILE_OUTPUT_STREAM_HPP
#define LS_STD_FILE_OUTPUT_STREAM_HPP

#include <ls_std/base/Class.hpp>
#include "File.hpp"
#include "IWriter.hpp"
#include <fstream>

namespace ls_std
{
  class FileOutputStream : public Class, public IWriter
  {
    public:

      explicit FileOutputStream(ls_std::File &_file);
      explicit FileOutputStream(ls_std::File &_file, bool _append);
      ~FileOutputStream() override;

      void close();
      bool write(const ls_std::byte_field &_data) override;

    private:

      bool append{};
      ls_std::File file;
      std::ofstream outputStream{};

      void _close();
      void _init();
  };
}

#endif
