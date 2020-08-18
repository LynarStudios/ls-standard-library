/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include "../base/Class.hpp"
#include "File.hpp"
#include "IReader.hpp"

namespace ls_std {
  class FileReader : public Class, IReader {
    public:

      explicit FileReader(File& _file);
      ~FileReader() = default;

      ls_std::byte* read() override;

    private:

      File file;
  };
}

#endif