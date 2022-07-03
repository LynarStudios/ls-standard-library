/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-06-26
 * Changed:         2022-07-03
 *
 * */

#ifndef LS_STD_MSVC_DLL_DEFINITIONS_HPP
#define LS_STD_MSVC_DLL_DEFINITIONS_HPP

#define DLL_EXPORT        __declspec(dllexport)
#define DLL_IMPORT        __declspec(dllimport)
#define LS_STD_DYNAMIC_GOAL      DLL_EXPORT

#endif
