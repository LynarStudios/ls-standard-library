/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-12-09
 *
 * */

#ifndef LS_STD_SOCKET_HPP
#define LS_STD_SOCKET_HPP

#include <ls_std/os/dynamic_goal.hpp>
#include <ls_std/core/Class.hpp>
#include "SocketParameter.hpp"
#include "SocketAddressMapperParameter.hpp"

namespace ls::std::network
{
  class LS_STD_DYNAMIC_GOAL Socket : public ls::std::core::Class
  {
    public:

      explicit Socket(const ls::std::network::SocketParameter& _parameter);
      ~Socket() override = default;

      [[nodiscard]] bool connect();
      [[nodiscard]] bool isInitialized() const;

    private:

      bool initialized{};
      ls::std::network::SocketParameter parameter{};
      #if defined(unix) || defined(__APPLE__)
      int unixDescriptor{};
      #endif

      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] bool _connectUnix() const;
      #endif
      [[nodiscard]] SocketAddressMapperParameter _createSocketAddressMapperParameter() const;
      [[nodiscard]] static bool _init(const ls::std::network::SocketParameter& _parameter);
      #if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static bool _initUnix(const ls::std::network::SocketParameter& _parameter);
      #endif
  };
}

#endif
