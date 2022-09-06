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
#if defined(unix) || defined(__APPLE__)
#include <dlfcn.h>
#endif

ls::std::os::RuntimeLibraryLoader::RuntimeLibraryLoader(ls::std::os::RuntimeLibraryLoaderParameter _parameter) : parameter(::std::move(_parameter))
{
  if (this->parameter.path.empty())
  {
    throw ls::std::core::IllegalArgumentException{};
  }
}

bool ls::std::os::RuntimeLibraryLoader::open()
{
  bool opened;

  #if defined(unix) || defined(__APPLE__)
  opened = this->_openUnix();
  #endif
  #ifdef _WIN32
  opened = this->_openWindows();
  #endif

  return opened;
}

#if defined(unix) || defined(__APPLE__)
bool ls::std::os::RuntimeLibraryLoader::_openUnix()
{
  this->handle = dlopen(this->parameter.path.c_str(), RTLD_LAZY);
  return this->handle != nullptr;
}
#endif
