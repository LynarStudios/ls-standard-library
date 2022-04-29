/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-04-29
 *
 * */

#ifndef LS_STD_TEST_DATA_MERCEDES_CAR_HPP
#define LS_STD_TEST_DATA_MERCEDES_CAR_HPP

#include "TestDataCar.hpp"
#include <ls_std/logic/IListener.hpp>
#include <ls_std/core/Class.hpp>

namespace ls_std_test
{
  class TestDataMercedesCar : public TestDataCar, public ls_std::IListener
  {
    public:

      TestDataMercedesCar();
      ~TestDataMercedesCar() = default;

      void listen(const ls_std::Class &_info) override;
  };
}

#endif
