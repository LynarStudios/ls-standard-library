/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#ifndef I_WRITER_HPP
#define I_WRITER_HPP

#include <vector>
#include "../base/Types.hpp"

namespace ls_std {
  class IWriter {
    public:

      IWriter() = default;
      ~IWriter() = default;

      virtual bool write(const std::vector<ls_std::byte>& _data) = 0;
  };
}

#endif
