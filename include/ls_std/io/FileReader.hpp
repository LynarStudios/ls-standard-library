/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_FILE_READER_HPP
#define LS_STD_FILE_READER_HPP

#include <ls_std/base/Class.hpp>
#include "File.hpp"
#include "IReader.hpp"

namespace ls_std {
  class FileReader : public Class, public IReader {
    public:

      explicit FileReader(File& _file);
      ~FileReader() = default;

      ls_std::byte_field read() override;
      void reset(File& _file);

    private:

      File file;

      static void _init(File &_file);
  };
}

#endif
