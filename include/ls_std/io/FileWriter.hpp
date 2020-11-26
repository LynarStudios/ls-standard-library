/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_FILE_WRITER_HPP
#define LS_STD_FILE_WRITER_HPP

#include <ls_std/base/Class.hpp>
#include "IWriter.hpp"
#include "File.hpp"

namespace ls_std {
  class FileWriter : public Class, public IWriter {
    public:

      explicit FileWriter(File& _file);
      ~FileWriter() override = default;

      void reset(File& _file);
      bool write(const ls_std::byte_field& _data) override;

    private:

      File file;

      static void _init(File& _file);
  };
}

#endif
