/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-25
 * Changed:         2022-12-25
 *
 * */

#ifndef LS_STD_LS_STD_COMMON_HPP
#define LS_STD_LS_STD_COMMON_HPP

#if defined(unix) || defined(__APPLE__)
#include <ls_std/common/api/io/PosixReader.hpp>
#include <ls_std/common/api/io/PosixWriter.hpp>
#include <ls_std/common/api/socket/PosixSocket.hpp>

#include <ls_std/common/interface/IPosixReader.hpp>
#include <ls_std/common/interface/IPosixSocket.hpp>
#include <ls_std/common/interface/IPosixWriter.hpp>
#endif

#endif
