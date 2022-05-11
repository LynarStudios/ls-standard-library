/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-11
 *
 * */

#ifndef LS_STD_TEST_DATA_MERCEDES_CAR_HPP
#define LS_STD_TEST_DATA_MERCEDES_CAR_HPP

#include "TestDataCar.hpp"
#include "ls_std/core/interface/IListener.hpp"
#include <ls_std/core/Class.hpp>

namespace ls_std_test
{
  class TestDataMercedesCar : public TestDataCar, public ls::std::core::IListener
  {
    public:

      TestDataMercedesCar();
      ~TestDataMercedesCar() = default;

      void listen(const ls::std::core::Class &_info) override;
  };
}

#endif
