/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-27
* Changed:         2023-03-28
*
* */

#include <ls-std/core/exception/ExceptionMessage.hpp>
#include <ls-std/core/exception/NotImplementedException.hpp>
#include <string>

using ls::std::core::Exception;
using ls::std::core::ExceptionMessage;
using ls::std::core::NotImplementedException;
using std::move;
using std::string;

NotImplementedException::NotImplementedException() : Exception("NotImplementedException")
{}

NotImplementedException::NotImplementedException(string _message) : NotImplementedException()
{
  this->message = ::move(_message);
}

NotImplementedException::~NotImplementedException() noexcept = default;

const char *NotImplementedException::what() const noexcept
{
  return this->_getIdentifiedMessage("method is not implemented and should not be used!");
}
