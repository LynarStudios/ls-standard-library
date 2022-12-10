/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-10
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

      explicit Socket(const ls::std::network::SocketParameter& _parameter);
      ~Socket() override = default;

      [[nodiscard]] bool bind();
      [[nodiscard]] bool connect();
      [[nodiscard]] bool isInitialized() const;

    private:

      bool initialized{};
      ls::std::network::SocketParameter parameter{};
      #if defined(unix) || defined(__APPLE__)
      ::std::shared_ptr<ls::std::core::interface_type::IPosixSocket> posixSocket{};
      int unixDescriptor{};
      #endif

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _bindUnix();
      [[nodiscard]] bool _connectUnix();
      #endif
      [[nodiscard]] SocketAddressMapperParameter _createSocketAddressMapperParameter() const;
      [[nodiscard]] bool _init(const ls::std::network::SocketParameter& _parameter);
      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _initUnix(const ls::std::network::SocketParameter& _parameter);
      void _selectUnixSocketApi(const ls::std::network::SocketParameter& _parameter);
      #endif
  };
}

#endif
