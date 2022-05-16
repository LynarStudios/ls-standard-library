/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2022-05-16
 *
 * */

#ifndef LS_STD_TEST_DATA_MERCEDES_CAR_HPP
#define LS_STD_TEST_DATA_MERCEDES_CAR_HPP

#include "TestDataCar.hpp"
#include "ls_std/core/interface/IListener.hpp"
#include "ls_std/core/Class.hpp"

namespace ls_std_event_test
{
  class TestDataMercedesCar : public ls_std_event_test::TestDataCar, public ls::std::core::interface::IListener
  {
    public:

      TestDataMercedesCar();
      ~TestDataMercedesCar() = default;

      void listen(const ls::std::core::Class &_info) override;
  };
}

#endif
