/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-05
* Changed:         2023-02-23
*
* */

#include <classes/core/ClassWrapper.hpp>

using ls::std::core::Class;
using test::core::ClassWrapper;

ClassWrapper::ClassWrapper() : Class("ClassWrapper")
{}

ClassWrapper::~ClassWrapper()
{
  Die();
}
