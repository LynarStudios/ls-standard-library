/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2022-05-16
 *
 * */

#ifndef LS_STD_STANDARD_OUTPUT_WRITER_HPP
#define LS_STD_STANDARD_OUTPUT_WRITER_HPP

#include <ls_std/core/interface/IWriter.hpp>

namespace ls
{
  namespace std
  {
    namespace io
    {
      class StandardOutputWriter : public ls::std::core::interface::IWriter
      {
        public:

          StandardOutputWriter() = default;
          ~StandardOutputWriter() = default;

          bool write(const ls::std::core::type::byte_field &_data) override;
      };
    }
  }
}

#endif
