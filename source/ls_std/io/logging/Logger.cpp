/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-11-06
 *
 * */

#include "../../../../include/ls_std/io/logging/Logger.hpp"
#include "../../time/Date.hpp"
#include "../../../../include/ls_std/io/NewLine.hpp"
#include "../../../../include/ls_std/boxing/String.hpp"

ls_std::Logger::Logger(const std::string &_path) : Class("Logger"),
file(ls_std::File{_path}),
logLevel(ls_std::LogLevelValue::INFO)
{
  this->_init();
}

void ls_std::Logger::close()
{
  this->outputStream->close();
}

void ls_std::Logger::debug(const ls_std::byte *_data)
{
  if(this->logLevel >= ls_std::LogLevelValue::DEBUG) {
    this->_log(_data, ls_std::LogLevel(ls_std::LogLevelValue::DEBUG));
  }
}

void ls_std::Logger::error(const ls_std::byte *_data)
{
  if(this->logLevel >= ls_std::LogLevelValue::ERR) {
    this->_log(_data, ls_std::LogLevel(ls_std::LogLevelValue::ERR));
  }
}

void ls_std::Logger::fatal(const ls_std::byte *_data)
{
  if(this->logLevel >= ls_std::LogLevelValue::FATAL) {
    this->_log(_data, ls_std::LogLevel(ls_std::LogLevelValue::FATAL));
  }
}

ls_std::LogLevel ls_std::Logger::getLogLevel()
{
  return this->logLevel;
}

void ls_std::Logger::info(const ls_std::byte *_data)
{
  if(this->logLevel >= ls_std::LogLevelValue::INFO) {
    this->_log(_data, ls_std::LogLevel(ls_std::LogLevelValue::INFO));
  }
}

void ls_std::Logger::setLogLevel(const ls_std::LogLevelValue &_logLevelValue)
{
  this->logLevel = _logLevelValue;
}

void ls_std::Logger::trace(const ls_std::byte *_data)
{
  if(this->logLevel >= ls_std::LogLevelValue::TRACE) {
    this->_log(_data, ls_std::LogLevel(ls_std::LogLevelValue::TRACE));
  }
}

void ls_std::Logger::warn(const ls_std::byte *_data)
{
  if(this->logLevel >= ls_std::LogLevelValue::WARN) {
    this->_log(_data, ls_std::LogLevel(ls_std::LogLevelValue::WARN));
  }
}

void ls_std::Logger::_init()
{
  if(!this->file.exists()) {
    this->file.createNewFile();
  }
}

void ls_std::Logger::_log(const ls_std::byte *_data, const ls_std::LogLevel& _logLevel)
{
  if(this->outputStream == nullptr) {
    this->outputStream = std::make_shared<ls_std::FileOutputStream>(this->file, true);
  }

  ls_std::Date date {};

  std::string message = "[" +
      date.toString() + "] " +
      ls_std::String {_logLevel.toString() + ":"}.padRight(10, ' ') +
      std::string(_data) +
      ls_std::NewLine::getUnixNewLine();

  outputStream->write(message);
}
