/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-26
 *
 * */

#ifndef LS_STD_SOCKET_HPP
#define LS_STD_SOCKET_HPP

#include <ls_std/os/dynamic_goal.hpp>
#include <ls_std/core/Class.hpp>
#include "SocketParameter.hpp"
#include "SocketAddressMapperParameter.hpp"
#include <memory>
#include <ls_std/core/types/Types.hpp>
#include <ls_std/core/interface/IReader.hpp>
#include <ls_std/core/interface/IWriter.hpp>

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL Socket : public ls::std::core::Class, public ls::std::core::interface_type::IReader, public ls::std::core::interface_type::IWriter
  {
    public:

      explicit Socket(ls::std::network::SocketParameter _parameter);
      ~Socket() override;

      // implementation

      [[nodiscard]] ls::std::core::type::byte_field read() override;
      [[nodiscard]] bool write(const ls::std::core::type::byte_field &_data) override;

      // other functionalities

      [[nodiscard]] bool accept();
      [[nodiscard]] bool bind();
      [[nodiscard]] bool close();
      [[nodiscard]] bool connect();
      [[nodiscard]] bool isInitialized() const;
      [[nodiscard]] bool listen();

    private:

      bool initialized{};
      ls::std::network::SocketParameter parameter{};
      ls::std::core::type::byte* readBuffer{};
      bool readBufferSet{};
      #if defined(unix) || defined(__APPLE__)
      int unixDescriptor{};
      #endif

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _acceptUnix();
      [[nodiscard]] bool _bindUnix();
      [[nodiscard]] bool _closeUnix();
      [[nodiscard]] bool _connectUnix();
      #endif
      [[nodiscard]] SocketAddressMapperParameter _createSocketAddressMapperParameter() const;
      void _init();
      void _initReadBuffer();
      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _initUnix();
      [[nodiscard]] bool _listenUnix();
      #endif
      ls::std::core::type::byte_field _read();
      #if defined(unix) || defined(__APPLE__)
      ls::std::core::type::byte_field _readUnix();
      void _setPosixReaderApi();
      void _setPosixSocketApi();
      void _setPosixWriterApi();
      #endif
      bool _write(const ls::std::core::type::byte_field &_data);
      #if defined(unix) || defined(__APPLE__)
      bool _writeUnix(const ls::std::core::type::byte_field &_data);
      #endif
  };
}

#endif
