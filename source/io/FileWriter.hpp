/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#ifndef FILE_WRITER_HPP
#define FILE_WRITER_HPP

#include "../base/Class.hpp"
#include "IWriter.hpp"
#include "File.hpp"

namespace ls_std {
  class FileWriter : public Class, IWriter {
    public:

      explicit FileWriter(File& _file);
      ~FileWriter() = default;

      bool write(const ls_std::byte* _data) override;

    private:

      File file;
  };
}

#endif
