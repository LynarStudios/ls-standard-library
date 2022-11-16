/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-11-16
 * Changed:         2022-11-16
 *
 * */

#include <ls_std/network/socket/Socket.hpp>

ls::std::network::Socket::Socket(const ls::std::network::SocketParameter &_parameter) : ls::std::core::Class("Socket"),
                                                                                        parameter(_parameter)
{}
