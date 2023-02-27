/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-02-23
 *
 * */

#include <ctime>
#include <iomanip>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/logging/Logger.hpp>
#if defined(_MSC_VER) || defined(__APPLE__)
  #include <sstream>
#endif

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::interface_type::IWriter;
using ls::std::core::type::byte_type;
using ls::std::io::Logger;
using ls::std::io::LogLevel;
using ls::std::io::LogLevelValue;
using ls::std::io::NewLine;
using std::localtime;
using std::put_time;
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::time;

Logger::Logger(const shared_ptr<IWriter> &_writer) : Class("Logger"), logLevel(LogLevelValue::INFO)
{
  this->_assignWriter(_writer);
}

Logger::~Logger() noexcept = default;

void Logger::debug(const byte_type *_data)
{
  if (this->logLevel >= LogLevelValue::DEBUG)
  {
    this->_log(_data, LogLevel(LogLevelValue::DEBUG));
  }
}

void Logger::error(const byte_type *_data)
{
  if (this->logLevel >= LogLevelValue::ERR)
  {
    this->_log(_data, LogLevel(LogLevelValue::ERR));
  }
}

void Logger::fatal(const byte_type *_data)
{
  if (this->logLevel >= LogLevelValue::FATAL)
  {
    this->_log(_data, LogLevel(LogLevelValue::FATAL));
  }
}

LogLevel Logger::getLogLevel()
{
  return this->logLevel;
}

void Logger::info(const byte_type *_data)
{
  if (this->logLevel >= LogLevelValue::INFO)
  {
    this->_log(_data, LogLevel(LogLevelValue::INFO));
  }
}

void Logger::setLogLevel(const LogLevelValue &_logLevelValue)
{
  this->logLevel = _logLevelValue;
}

void Logger::trace(const byte_type *_data)
{
  if (this->logLevel >= LogLevelValue::TRACE)
  {
    this->_log(_data, LogLevel(LogLevelValue::TRACE));
  }
}

void Logger::warn(const byte_type *_data)
{
  if (this->logLevel >= LogLevelValue::WARN)
  {
    this->_log(_data, LogLevel(LogLevelValue::WARN));
  }
}

void Logger::_assignWriter(const shared_ptr<IWriter> &_writer)
{
  NullPointerArgumentEvaluator{_writer, "writer reference is null!"}.evaluate();
  this->writer = _writer;
}

string Logger::_buildCharacterChain(size_t _amount)
{
  string fillContent{};

  for (size_t iteration{}; iteration < _amount; iteration++)
  {
    fillContent += ' ';
  }

  return fillContent;
}

string Logger::_createFillContent(const string &_text)
{
  size_t padSize = 10;
  size_t fillSize = _text.size() > padSize ? 0 : padSize - _text.size();
  string fillContent{};

  if (fillSize > 0)
  {
    fillContent = Logger::_buildCharacterChain(fillSize);
  }

  return fillContent;
}

string Logger::_generateTimeString(tm *_localTime)
{
  stringstream _stream{};
  _stream << put_time(_localTime, "%Y-%m-%d %H:%M:%S");

  return _stream.str();
}

void Logger::_log(const byte_type *_data, const LogLevel &_logLevel)
{
  time_t timestamp = ::time(nullptr);
  tm *localTime = localtime(&timestamp);

  string logLevelString = Logger::_padRight(string{_logLevel.toString() + ":"});
  string message = "[" + Logger::_generateTimeString(localTime) + "] " + logLevelString + string(_data) + NewLine::getUnixNewLine();
  this->writer->write(message);
}

string Logger::_padRight(const string &_text)
{
  return _text + Logger::_createFillContent(_text);
}
