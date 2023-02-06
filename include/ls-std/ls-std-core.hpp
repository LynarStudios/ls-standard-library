/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-13
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_LS_STD_CORE_HPP
#define LS_STD_LS_STD_CORE_HPP

#include <ls-std/core/exception/EventNotHandledException.hpp>
#include <ls-std/core/exception/EventNotSubscribedException.hpp>
#include <ls-std/core/exception/FileNotFoundException.hpp>
#include <ls-std/core/exception/FileOperationException.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>
#include <ls-std/core/exception/IncompleteJsonException.hpp>
#include <ls-std/core/exception/NullPointerException.hpp>

#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/core/interface/IEncoding.hpp>
#include <ls-std/core/interface/IEventSubscriber.hpp>
#include <ls-std/core/interface/IListener.hpp>
#include <ls-std/core/interface/IReader.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/core/interface/IStorable.hpp>
#include <ls-std/core/interface/IWriter.hpp>

#include <ls-std/core/types/EventTypes.hpp>
#include <ls-std/core/types/KvTypes.hpp>
#include <ls-std/core/types/Types.hpp>

#if _WIN32
  #include <ls-std/core/utils/WindowsUtils.hpp>
#endif

#include <ls-std/core/Class.hpp>
#include <ls-std/core/LibraryVersion.hpp>
#include <ls-std/core/Version.hpp>

#endif
