/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-06-29
 * Changed:         2022-10-23
 *
 * */

#ifndef LS_STD_DYNAMIC_GOAL_HPP
#define LS_STD_DYNAMIC_GOAL_HPP

#if defined(_WIN32) && defined(_MSC_VER)
#include <ls_std/os/library/goals/windows/msvc_dll_definitions.hpp>
#endif
#if defined(unix) || defined(__APPLE__) || defined(_WIN32) && defined(__GNUC__)
#include <ls_std/os/library/goals/unix/unix_so_definitions.hpp>
#endif

#endif
