/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2022-05-20
 *
 * */

#ifndef LS_STD_IO_TEST_DATA_FACTORY_HPP
#define LS_STD_IO_TEST_DATA_FACTORY_HPP

#include <memory>
#include <ls_std/ls_std_io.hpp>

namespace ls_std_io_test
{
  class TestDataFactory
  {
    public:

      TestDataFactory() = default;
      ~TestDataFactory() = default;

      static ::std::shared_ptr<ls::std::io::XmlNode> createXmlContent();
  };
}

#endif