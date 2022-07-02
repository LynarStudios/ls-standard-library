/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-07-02
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
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::io
{
  class DYNAMIC_GOAL Logger : public ls::std::core::Class
  {
    public:

      explicit Logger(const ::std::shared_ptr<ls::std::core::interface_type::IWriter> &_writer);
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
      ::std::shared_ptr<ls::std::core::interface_type::IWriter> writer{};

      void _assignWriter(const ::std::shared_ptr<ls::std::core::interface_type::IWriter> &_writer);
      static ::std::string _buildCharacterChain(size_t _amount);
      static ::std::string _createFillContent(const ::std::string &_text);
      static ::std::string _generateTimeString(tm *_localTime);
      void _log(const ls::std::core::type::byte *_data, const ls::std::io::LogLevel &_logLevel);
      static ::std::string _padRight(const ::std::string &_text);
  };
}

#endif
