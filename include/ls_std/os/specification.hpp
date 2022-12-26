/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-12-26
 * Changed:         2022-12-26
 *
 * */

#ifndef LS_STD_SPECIFICATION_HPP
#define LS_STD_SPECIFICATION_HPP

#if defined(unix) || defined(__APPLE__)
#define LS_STD_UNIX_PLATFORM (1==1)
#else
#define LS_STD_UNIX_PLATFORM (1==0)
#endif

#ifdef _WIN32
#define LS_STD_WINDOWS_PLATFORM (1==1)
#else
#define LS_STD_WINDOWS_PLATFORM (1==0)
#endif

#endif
