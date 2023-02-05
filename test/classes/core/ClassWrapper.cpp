/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <classes/core/ClassWrapper.hpp>

ls_std_core_test::ClassWrapper::ClassWrapper() : ls::std::core::Class("ClassWrapper")
{}

ls_std_core_test::ClassWrapper::~ClassWrapper()
{
  Die();
}
