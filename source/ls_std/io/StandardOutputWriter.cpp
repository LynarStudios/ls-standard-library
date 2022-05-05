/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2022-05-05
 *
 * */

#include <iostream>
#include <ls_std/io/StandardOutputWriter.hpp>

bool ls::StandardOutputWriter::write(const ls::byte_field &_data)
{
  std::cout << _data;
  return !std::cout.fail();
}
