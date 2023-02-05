/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_IO_TEST_DATA_FACTORY_HPP
#define LS_STD_IO_TEST_DATA_FACTORY_HPP

#include <ls-std/ls-std-io.hpp>
#include <memory>

namespace test::io
{
  class TestDataFactory
  {
    public:

      TestDataFactory();
      ~TestDataFactory();

      static ::std::shared_ptr<ls::std::io::XmlNode> createXmlContent();
  };
}

#endif
