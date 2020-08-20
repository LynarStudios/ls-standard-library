/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-08-20
 *
 * */

#ifndef FILE_OUTPUT_STREAM_HPP
#define FILE_OUTPUT_STREAM_HPP

#include "../base/Class.hpp"
#include "File.hpp"
#include "IWriter.hpp"
#include <fstream>

namespace ls_std {
  class FileOutputStream : public Class, IWriter {
    public:

      explicit FileOutputStream(File& _file);
      ~FileOutputStream();

      void close();
      bool write(const ls_std::byte* _data) override;

    private:

      File file;
      std::ofstream outputStream {};

      void _close();
  };
}

#endif
