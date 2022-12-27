/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-27
 * Changed:         2022-12-27
 *
 * */

#ifndef LS_STD_SOCKET_OPERATION_FAILED_EXCEPTION_HPP
#define LS_STD_SOCKET_OPERATION_FAILED_EXCEPTION_HPP

#include <exception>

namespace ls::std::core
{
  class SocketOperationFailedException : public ::std::exception
  {
    public:

      explicit SocketOperationFailedException() = default;

      [[nodiscard]] const char *what() const noexcept override
      {
        return "SocketOperationFailedException thrown - operation on socket was not successful!";
      }
  };
}

#endif
