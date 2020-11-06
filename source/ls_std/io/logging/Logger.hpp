/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_LOGGER_HPP
#define LS_STD_LOGGER_HPP

#include "../../../../include/ls_std/base/Class.hpp"
#include "LogLevel.hpp"
#include "../IWriter.hpp"
#include "../File.hpp"
#include "../FileOutputStream.hpp"
#include <string>

namespace ls_std {
  class Logger : public Class {
    public:

      explicit Logger(const std::string& _path);
      ~Logger() = default;

      void close();
      void debug(const ls_std::byte* _data);
      void error(const ls_std::byte* _data);
      void fatal(const ls_std::byte* _data);
      ls_std::LogLevel getLogLevel();
      void info(const ls_std::byte* _data);
      void setLogLevel(const ls_std::LogLevelValue& _logLevelValue);
      void trace(const ls_std::byte* _data);
      void warn(const ls_std::byte* _data);

    private:

      ls_std::File file;
      ls_std::LogLevel logLevel {};
      std::shared_ptr<ls_std::FileOutputStream> outputStream {};

      void _init();
      void _log(const ls_std::byte* _data, const ls_std::LogLevel& _logLevel);
  };
}

#endif
