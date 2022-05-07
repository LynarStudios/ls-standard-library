/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-07
 *
 * */

#include <ls_std/io/logging/Logger.hpp>
#include <ls_std/time/Date.hpp>
#include <ls_std/io/NewLine.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::Logger::Logger(const ::std::shared_ptr<ls::IWriter> &_writer)
    : ls::Class("Logger"),
      logLevel(ls::LogLevelValue::INFO)
{
  this->_assignWriter(_writer);
}

void ls::Logger::debug(const ls::byte *_data)
{
  if (this->logLevel >= ls::LogLevelValue::DEBUG)
  {
    this->_log(_data, ls::LogLevel(ls::LogLevelValue::DEBUG));
  }
}

void ls::Logger::error(const ls::byte *_data)
{
  if (this->logLevel >= ls::LogLevelValue::ERR)
  {
    this->_log(_data, ls::LogLevel(ls::LogLevelValue::ERR));
  }
}

void ls::Logger::fatal(const ls::byte *_data)
{
  if (this->logLevel >= ls::LogLevelValue::FATAL)
  {
    this->_log(_data, ls::LogLevel(ls::LogLevelValue::FATAL));
  }
}

ls::LogLevel ls::Logger::getLogLevel()
{
  return this->logLevel;
}

void ls::Logger::info(const ls::byte *_data)
{
  if (this->logLevel >= ls::LogLevelValue::INFO)
  {
    this->_log(_data, ls::LogLevel(ls::LogLevelValue::INFO));
  }
}

void ls::Logger::setLogLevel(const ls::LogLevelValue &_logLevelValue)
{
  this->logLevel = _logLevelValue;
}

void ls::Logger::trace(const ls::byte *_data)
{
  if (this->logLevel >= ls::LogLevelValue::TRACE)
  {
    this->_log(_data, ls::LogLevel(ls::LogLevelValue::TRACE));
  }
}

void ls::Logger::warn(const ls::byte *_data)
{
  if (this->logLevel >= ls::LogLevelValue::WARN)
  {
    this->_log(_data, ls::LogLevel(ls::LogLevelValue::WARN));
  }
}

void ls::Logger::_assignWriter(const ::std::shared_ptr<ls::IWriter> &_writer)
{
  if (_writer == nullptr)
  {
    throw ls::IllegalArgumentException{};
  }

  this->writer = _writer;
}

void ls::Logger::_log(const ls::byte *_data, const ls::LogLevel &_logLevel)
{
  ls::std::time::Date date{};
  ::std::string message = "[" + date.toString() + "] " + ls::std::boxing::String{_logLevel.toString() + ":"}.padRight(10, ' ') + ::std::string(_data) + ls::NewLine::getUnixNewLine();
  this->writer->write(message);
}
