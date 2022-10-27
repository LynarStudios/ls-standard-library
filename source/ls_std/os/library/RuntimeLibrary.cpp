/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-10-27
 * Changed:         2022-10-27
 *
 * */

#include <ls_std/os/library/RuntimeLibrary.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

bool ls::std::os::RuntimeLibrary::addSymbol(const ls::std::core::type::runtime_library_entry& _entry)
{
  bool validEntry = this->_isValidEntry(_entry);
  bool added{};

  if (validEntry && !this->_hasSymbol(_entry.first))
  {
    added = this->symbols.emplace(_entry).second;
  }
  else
  {
    if (!validEntry)
    {
      throw ls::std::core::IllegalArgumentException{};
    }
  }

  return added;
}

void *ls::std::os::RuntimeLibrary::getSymbol(const ::std::string &_symbolName)
{
  return this->_getSymbol(_symbolName);
}

bool ls::std::os::RuntimeLibrary::hasSymbol(const ::std::string &_symbolName)
{
  return this->_hasSymbol(_symbolName);
}

void *ls::std::os::RuntimeLibrary::_getSymbol(const ::std::string &_symbolName)
{
  void* symbol{};

  if (this->_hasSymbol(_symbolName))
  {
    symbol = this->symbols.at(_symbolName);
  }

  return symbol;
}

bool ls::std::os::RuntimeLibrary::_hasSymbol(const ::std::string &_symbolName)
{
  return this->symbols.find(_symbolName) != this->symbols.end();
}

bool ls::std::os::RuntimeLibrary::_isValidEntry(const ls::std::core::type::runtime_library_entry &_entry)
{
  return !_entry.first.empty() && _entry.second != nullptr;
}
