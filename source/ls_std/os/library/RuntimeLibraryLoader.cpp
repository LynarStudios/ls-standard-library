/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-09-06
 * Changed:         2022-10-20
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

bool ls::std::os::RuntimeLibraryLoader::close()
{
  return this->_close();
}

void *ls::std::os::RuntimeLibraryLoader::getSymbol(const ::std::string &_symbolName)
{
  #if defined(unix) || defined(__APPLE__)
  return this->_getSymbolUnix(_symbolName);
  #endif
}

bool ls::std::os::RuntimeLibraryLoader::hasSymbol(const ::std::string &_symbolName)
{
  return this->_hasSymbolUnix(_symbolName);
}

bool ls::std::os::RuntimeLibraryLoader::loadSymbol(const ::std::string &_symbolName)
{
  bool loaded{};

  #if defined(unix) || defined(__APPLE__)
  loaded = this->_loadSymbolUnix(_symbolName);
  #endif

  return loaded;
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

bool ls::std::os::RuntimeLibraryLoader::_close()
{
  bool closed{};

  if (this->handle != nullptr)
  {
    closed = dlclose(this->handle) == 0;
  }

  return closed;
}

void *ls::std::os::RuntimeLibraryLoader::_getSymbolUnix(const ::std::string &_symbolName)
{
  void* symbol{};

  if (this->_hasSymbolUnix(_symbolName))
  {
    symbol = this->symbols.at(_symbolName);
  }

  return symbol;
}

bool ls::std::os::RuntimeLibraryLoader::_hasSymbolUnix(const ::std::string &_symbolName)
{
  return this->symbols.find(_symbolName) != this->symbols.end();
}

bool ls::std::os::RuntimeLibraryLoader::_loadSymbolUnix(const ::std::string& _symbolName)
{
  bool loaded{};

  if (!this->_hasSymbolUnix(_symbolName))
  {
    void* symbol = dlsym(this->handle, _symbolName.c_str());
    this->symbols.insert(::std::pair<::std::string, void*>(_symbolName, symbol));
    loaded = symbol != nullptr;
  }

  return loaded;
}

bool ls::std::os::RuntimeLibraryLoader::_openUnix()
{
  this->handle = dlopen(this->parameter.path.c_str(), RTLD_LAZY);
  return this->handle != nullptr;
}
#endif
