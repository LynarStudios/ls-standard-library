/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2021-05-01
 *
 * */

#ifndef LS_STD_STANDARD_OUTPUT_WRITER_HPP
#define LS_STD_STANDARD_OUTPUT_WRITER_HPP

#include "IWriter.hpp"

namespace ls_std
{
  class StandardOutputWriter : public ls_std::IWriter
  {
    public:

      StandardOutputWriter() = default;
      ~StandardOutputWriter() = default;

      bool write(const ls_std::byte_field &_data) override;
  };
}

#endif
