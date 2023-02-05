/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-05
*
* */

#include <classes/core/ClassWrapper.hpp>

test::core::ClassWrapper::ClassWrapper() : ls::std::core::Class("ClassWrapper")
{}

test::core::ClassWrapper::~ClassWrapper()
{
  Die();
}
