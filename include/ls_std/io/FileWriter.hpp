/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_FILE_WRITER_HPP
#define LS_STD_FILE_WRITER_HPP

#include <ls_std/core/Class.hpp>
#include "IWriter.hpp"
#include "File.hpp"

namespace ls
{
  namespace std
  {
    namespace io
    {
      class FileWriter : public ls::std::core::Class, public ls::std::io::IWriter
      {
        public:

          explicit FileWriter(ls::std::io::File &_file);
          ~FileWriter() override = default;

          void reset(ls::std::io::File &_file);
          bool write(const ls::std::core::byte_field &_data) override;

        private:

          ls::std::io::File file;

          static void _init(ls::std::io::File &_file);
      };
    }
  }
}

#endif
