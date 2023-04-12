/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-04-12
 *
 * */

#ifndef LS_STD_LOGGER_HPP
#define LS_STD_LOGGER_HPP

#include "LogLevel.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IWriter.hpp>
#include <ls-std/io/File.hpp>
#include <ls-std/io/FileOutputStream.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL Logger : public ls::std::core::Class
  {
    public:

      explicit Logger(const ::std::shared_ptr<ls::std::core::interface_type::IWriter> &_writer);
      ~Logger() noexcept override;

      void debug(const ls::std::core::type::byte_type *_data);
      void error(const ls::std::core::type::byte_type *_data);
      void fatal(const ls::std::core::type::byte_type *_data);
      [[nodiscard]] ls::std::io::LogLevel getLogLevel();
      void hideLogLevel();
      void info(const ls::std::core::type::byte_type *_data);
      void setLogLevel(const ls::std::io::LogLevelValue &_logLevelValue);
      void showLogLevel();
      void trace(const ls::std::core::type::byte_type *_data);
      void warn(const ls::std::core::type::byte_type *_data);

    private:

      bool displayLogLevel{};
      ls::std::io::LogLevel logLevel{};
      ::std::shared_ptr<ls::std::core::interface_type::IWriter> writer{};

      void _assignWriter(const ::std::shared_ptr<ls::std::core::interface_type::IWriter> &_writer);
      [[nodiscard]] static ::std::string _buildCharacterChain(size_t _amount);
      [[nodiscard]] static ::std::string _createFillContent(const ::std::string &_text);
      [[nodiscard]] static ::std::string _generateTimeString(tm *_localTime);
      [[nodiscard]] ::std::string _getLogLevelString(const ls::std::io::LogLevel &_logLevel) const;
      void _log(const ls::std::core::type::byte_type *_data, const ls::std::io::LogLevel &_logLevel);
      [[nodiscard]] static ::std::string _padRight(const ::std::string &_text);
  };
}

#endif
