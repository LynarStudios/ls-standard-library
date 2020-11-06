/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2020-11-06
 *
 * */

#include <iostream>
#include "StandardOutputWriter.hpp"

bool ls_std::StandardOutputWriter::write(const ls_std::byte_field &_data)
{
  std::cout << _data << std::endl;
  return !_data.empty();
}
