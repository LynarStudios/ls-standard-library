/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_TEST_DATA_CAR_HPP
#define LS_STD_TEST_DATA_CAR_HPP

#include <string>

namespace ls_std_test
{
  class TestDataCar
  {
    public:

      TestDataCar();
      ~TestDataCar() = default;

      std::string getColor();
      void setColor(std::string _color);

    private:

      std::string color{};
  };
}

#endif
