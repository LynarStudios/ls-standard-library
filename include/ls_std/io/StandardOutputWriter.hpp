/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_STANDARD_OUTPUT_WRITER_HPP
#define LS_STD_STANDARD_OUTPUT_WRITER_HPP

#include "IWriter.hpp"

namespace ls
{
  class StandardOutputWriter : public ls::IWriter
  {
    public:

      StandardOutputWriter() = default;
      ~StandardOutputWriter() = default;

      bool write(const ls::byte_field &_data) override;
  };
}

#endif
