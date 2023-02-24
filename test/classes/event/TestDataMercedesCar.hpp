/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-23
 *
 * */

#ifndef LS_STD_TEST_DATA_MERCEDES_CAR_HPP
#define LS_STD_TEST_DATA_MERCEDES_CAR_HPP

#include "TestDataCar.hpp"
#include <ls-std/ls-std-core.hpp>

namespace test::event
{
  class TestDataMercedesCar : public test::event::TestDataCar, public ls::std::core::interface_type::IListener
  {
    public:

      TestDataMercedesCar();
      ~TestDataMercedesCar() noexcept override;

      void listen(const ls::std::core::Class &_info) override;
  };
}

#endif
