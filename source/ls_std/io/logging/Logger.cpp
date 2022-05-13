/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-13
 *
 * */

#include <ls_std/io/logging/Logger.hpp>
#include <ctime>
#include <iomanip>
#include <ls_std/io/NewLine.hpp>
#include <ls_std/boxing/String.hpp> // FIXME: remove "boxing" dependency from "io" module
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::io::Logger::Logger(const ::std::shared_ptr<ls::std::core::IWriter> &_writer)
    : ls::std::core::Class("Logger"),
      logLevel(ls::std::io::LogLevelValue::INFO)
{
  this->_assignWriter(_writer);
}

void ls::std::io::Logger::debug(const ls::std::core::type::byte *_data)
{
  if (this->logLevel >= ls::std::io::LogLevelValue::DEBUG)
  {
    this->_log(_data, ls::std::io::LogLevel(ls::std::io::LogLevelValue::DEBUG));
  }
}

void ls::std::io::Logger::error(const ls::std::core::type::byte *_data)
{
  if (this->logLevel >= ls::std::io::LogLevelValue::ERR)
  {
    this->_log(_data, ls::std::io::LogLevel(ls::std::io::LogLevelValue::ERR));
  }
}

void ls::std::io::Logger::fatal(const ls::std::core::type::byte *_data)
{
  if (this->logLevel >= ls::std::io::LogLevelValue::FATAL)
  {
    this->_log(_data, ls::std::io::LogLevel(ls::std::io::LogLevelValue::FATAL));
  }
}

ls::std::io::LogLevel ls::std::io::Logger::getLogLevel()
{
  return this->logLevel;
}

void ls::std::io::Logger::info(const ls::std::core::type::byte *_data)
{
  if (this->logLevel >= ls::std::io::LogLevelValue::INFO)
  {
    this->_log(_data, ls::std::io::LogLevel(ls::std::io::LogLevelValue::INFO));
  }
}

void ls::std::io::Logger::setLogLevel(const ls::std::io::LogLevelValue &_logLevelValue)
{
  this->logLevel = _logLevelValue;
}

void ls::std::io::Logger::trace(const ls::std::core::type::byte *_data)
{
  if (this->logLevel >= ls::std::io::LogLevelValue::TRACE)
  {
    this->_log(_data, ls::std::io::LogLevel(ls::std::io::LogLevelValue::TRACE));
  }
}

void ls::std::io::Logger::warn(const ls::std::core::type::byte *_data)
{
  if (this->logLevel >= ls::std::io::LogLevelValue::WARN)
  {
    this->_log(_data, ls::std::io::LogLevel(ls::std::io::LogLevelValue::WARN));
  }
}

void ls::std::io::Logger::_assignWriter(const ::std::shared_ptr<ls::std::core::IWriter> &_writer)
{
  if (_writer == nullptr)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->writer = _writer;
}

::std::string ls::std::io::Logger::_generateTimeString(tm *_localTime)
{
  ::std::stringstream _stream{};
  _stream << ::std::put_time(_localTime, "%Y-%m-%d %H:%M:%S");

  return _stream.str();
}

void ls::std::io::Logger::_log(const ls::std::core::type::byte *_data, const ls::std::io::LogLevel &_logLevel)
{
  time_t timestamp = ::std::time(nullptr);
  tm *localTime = ::std::localtime(&timestamp);

  ::std::string message = "[" + ls::std::io::Logger::_generateTimeString(localTime) + "] " + ls::std::boxing::String{_logLevel.toString() + ":"}.padRight(10, ' ') + ::std::string(_data) + ls::std::io::NewLine::getUnixNewLine();
  this->writer->write(message);
}
