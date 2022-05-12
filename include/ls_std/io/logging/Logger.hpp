/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_LOGGER_HPP
#define LS_STD_LOGGER_HPP

#include <ls_std/core/Class.hpp>
#include "LogLevel.hpp"
#include <ls_std/core/interface/IWriter.hpp>
#include <ls_std/io/File.hpp>
#include <ls_std/io/FileOutputStream.hpp>
#include <string>

namespace ls
{
  namespace std
  {
    namespace io
    {
      class Logger : public ls::std::core::Class
      {
        public:

          explicit Logger(const ::std::shared_ptr<ls::std::core::IWriter> &_writer);
          ~Logger() override = default;

          void debug(const ls::std::core::type::byte *_data);
          void error(const ls::std::core::type::byte *_data);
          void fatal(const ls::std::core::type::byte *_data);
          ls::std::io::LogLevel getLogLevel();
          void info(const ls::std::core::type::byte *_data);
          void setLogLevel(const ls::std::io::LogLevelValue &_logLevelValue);
          void trace(const ls::std::core::type::byte *_data);
          void warn(const ls::std::core::type::byte *_data);

        private:

          ls::std::io::LogLevel logLevel{};
          ::std::shared_ptr<ls::std::core::IWriter> writer{};

          void _assignWriter(const ::std::shared_ptr<ls::std::core::IWriter> &_writer);
          void _log(const ls::std::core::type::byte *_data, const ls::std::io::LogLevel &_logLevel);
      };
    }
  }
}

#endif
