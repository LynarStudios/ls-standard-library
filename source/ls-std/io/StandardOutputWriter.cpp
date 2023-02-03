/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2023-02-03
 *
 * */

#include <iostream>
#include <ls-std/io/StandardOutputWriter.hpp>

bool ls::std::io::StandardOutputWriter::write(const ls::std::core::type::byte_field &_data)
{
  ::std::cout << _data;
  return !::std::cout.fail();
}
