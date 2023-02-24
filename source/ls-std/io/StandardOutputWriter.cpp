/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-06
 * Changed:         2023-02-23
 *
 * */

#include <iostream>
#include <ls-std/io/StandardOutputWriter.hpp>

using ls::std::core::type::byte_field;
using ls::std::io::StandardOutputWriter;
using std::cout;

StandardOutputWriter::StandardOutputWriter() = default;

StandardOutputWriter::~StandardOutputWriter() noexcept = default;

bool StandardOutputWriter::write(const byte_field &_data)
{
  cout << _data;
  return !cout.fail();
}
