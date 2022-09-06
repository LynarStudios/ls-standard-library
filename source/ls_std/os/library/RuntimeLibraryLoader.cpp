/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-09-06
 *
 * */

#include <ls_std/os/library/RuntimeLibraryLoader.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::os::RuntimeLibraryLoader::RuntimeLibraryLoader(ls::std::os::RuntimeLibraryLoaderParameter _parameter) : parameter(::std::move(_parameter))
{
  if (this->parameter.path.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }
}


