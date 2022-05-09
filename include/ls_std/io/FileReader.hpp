/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_FILE_READER_HPP
#define LS_STD_FILE_READER_HPP

#include <ls_std/core/Class.hpp>
#include "File.hpp"
#include "IReader.hpp"

namespace ls
{
  class FileReader : public ls::std::core::Class, public ls::IReader
  {
    public:

      explicit FileReader(ls::File &_file);
      ~FileReader() override = default;

      ls::std::core::byte_field read() override;
      void reset(ls::File &_file);

    private:

      ls::File file;

      static void _init(ls::File &_file);
  };
}

#endif
