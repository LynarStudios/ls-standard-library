/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-04-24
 *
 * */

#include "SerializableTestFactory.hpp"

std::shared_ptr<ls_std::Class> ls_std_test::SerializableTestFactory::build()
{
  return std::make_shared<ls_std::Class>();
}
