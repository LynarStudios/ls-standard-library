/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_TEST_DATA_CAR_HPP
#define LS_STD_TEST_DATA_CAR_HPP

#include <string>

namespace ls_std_event_test
{
  class TestDataCar
  {
    public:

      TestDataCar();
      virtual ~TestDataCar();

      ::std::string getColor();
      void setColor(::std::string _color);

    private:

      ::std::string color{};
  };
}

#endif
