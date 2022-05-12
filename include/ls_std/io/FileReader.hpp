/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_FILE_READER_HPP
#define LS_STD_FILE_READER_HPP

#include <ls_std/core/Class.hpp>
#include "File.hpp"
#include <ls_std/core/interface/IReader.hpp>

namespace ls
{
  namespace std
  {
    namespace io
    {
      class FileReader : public ls::std::core::Class, public ls::std::core::IReader
      {
        public:

          explicit FileReader(ls::std::io::File &_file);
          ~FileReader() override = default;

          ls::std::core::type::byte_field read() override;
          void reset(ls::std::io::File &_file);

        private:

          ls::std::io::File file;

          static void _init(ls::std::io::File &_file);
      };
    }
  }
}

#endif
