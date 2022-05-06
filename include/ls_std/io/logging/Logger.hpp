/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_LOGGER_HPP
#define LS_STD_LOGGER_HPP

#include <ls_std/core/Class.hpp>
#include "LogLevel.hpp"
#include <ls_std/io/IWriter.hpp>
#include <ls_std/io/File.hpp>
#include <ls_std/io/FileOutputStream.hpp>
#include <string>

namespace ls
{
  class Logger : public ls::Class
  {
    public:

      explicit Logger(const ::std::shared_ptr<ls::IWriter> &_writer);
      ~Logger() override = default;

      void debug(const ls::byte *_data);
      void error(const ls::byte *_data);
      void fatal(const ls::byte *_data);
      ls::LogLevel getLogLevel();
      void info(const ls::byte *_data);
      void setLogLevel(const ls::LogLevelValue &_logLevelValue);
      void trace(const ls::byte *_data);
      void warn(const ls::byte *_data);

    private:

      ls::LogLevel logLevel{};
      ::std::shared_ptr<ls::IWriter> writer{};

      void _assignWriter(const ::std::shared_ptr<ls::IWriter> &_writer);
      void _log(const ls::byte *_data, const ls::LogLevel &_logLevel);
  };
}

#endif
