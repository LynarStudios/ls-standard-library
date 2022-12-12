/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-13
 * Changed:         2022-12-12
 *
 * */

#ifndef LS_STD_LS_STD_CORE_HPP
#define LS_STD_LS_STD_CORE_HPP

#include <ls_std/core/exception/EventNotHandledException.hpp>
#include <ls_std/core/exception/EventNotSubscribedException.hpp>
#include <ls_std/core/exception/FileNotFoundException.hpp>
#include <ls_std/core/exception/FileOperationException.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>
#include <ls_std/core/exception/IllegalArithmeticOperationException.hpp>
#include <ls_std/core/exception/IncompleteJsonException.hpp>
#include <ls_std/core/exception/NullPointerException.hpp>
#include <ls_std/core/exception/WrongProtocolException.hpp>

#include <ls_std/core/interface/IBoxing.hpp>
#include <ls_std/core/interface/IEncoding.hpp>
#include <ls_std/core/interface/IEventSubscriber.hpp>
#include <ls_std/core/interface/IListener.hpp>
#include <ls_std/core/interface/IPosixSocket.hpp>
#include <ls_std/core/interface/IReader.hpp>
#include <ls_std/core/interface/ISerializable.hpp>
#include <ls_std/core/interface/IStorable.hpp>
#include <ls_std/core/interface/IWriter.hpp>

#include <ls_std/core/types/EventTypes.hpp>
#include <ls_std/core/types/KvTypes.hpp>
#include <ls_std/core/types/SocketTypes.hpp>
#include <ls_std/core/types/Types.hpp>

#include <ls_std/core/utils/RegexUtils.hpp>
#include <ls_std/core/utils/STLUtils.hpp>
#if _WIN32
#include <ls_std/core/utils/WindowsUtils.hpp>
#endif

#include <ls_std/core/Class.hpp>
#include <ls_std/core/LibraryVersion.hpp>
#include <ls_std/core/Version.hpp>

#endif
