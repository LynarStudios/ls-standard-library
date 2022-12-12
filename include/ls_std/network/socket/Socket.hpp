/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-11
 *
 * */

#ifndef LS_STD_SOCKET_HPP
#define LS_STD_SOCKET_HPP

#include <ls_std/os/dynamic_goal.hpp>
#include <ls_std/core/Class.hpp>
#if defined(unix) || defined(__APPLE__)
#include "PosixSocket.hpp"
#endif
#include "SocketParameter.hpp"
#include "SocketAddressMapperParameter.hpp"
#include <memory>

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL Socket : public ls::std::core::Class
  {
    public:

      explicit Socket(ls::std::network::SocketParameter _parameter);
      ~Socket() override = default;

      [[nodiscard]] bool accept();
      [[nodiscard]] bool bind();
      [[nodiscard]] bool close();
      [[nodiscard]] bool connect();
      [[nodiscard]] bool isInitialized() const;
      [[nodiscard]] bool listen();

    private:

      bool initialized{};
      ls::std::network::SocketParameter parameter{};
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
      [[nodiscard]] bool _init();
      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _initUnix();
      [[nodiscard]] bool _listenUnix();
      void _setUnixSocketApi();
      #endif
  };
}

#endif
