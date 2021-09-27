/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-29
 * Changed:         2021-09-18
 *
 * */

#ifndef LS_STD_LS_STD_HPP
#define LS_STD_LS_STD_HPP

#if _WIN32
#include <winsock2.h>
#endif

#include "base/Class.hpp"
#include "base/Types.hpp"
#include "base/Version.hpp"
#include "base/LibraryVersion.hpp"

#include "boxing/IBoxing.hpp"
#include "boxing/Boolean.hpp"
#include "boxing/Double.hpp"
#include "boxing/Float.hpp"
#include "boxing/Integer.hpp"
#include "boxing/Long.hpp"
#include "boxing/String.hpp"

#include "exception/EventNotHandledException.hpp"
#include "exception/EventNotSubscribedException.hpp"
#include "exception/FileNotFoundException.hpp"
#include "exception/FileOperationException.hpp"
#include "exception/IllegalArgumentException.hpp"
#include "exception/IllegalArithmeticOperationException.hpp"
#include "exception/IncompleteJsonException.hpp"
#include "exception/NullPointerException.hpp"

#include "io/logging/LogLevel.hpp"
#include "io/logging/LogLevelValue.hpp"
#include "io/logging/Logger.hpp"
#include "io/xml/XmlReader.hpp"
#include "io/xml/XmlParseMode.hpp"
#include "io/xml/XmlParseParameter.hpp"
#include "io/xml/XmlNode.hpp"
#include "io/xml/XmlDocument.hpp"
#include "io/xml/XmlDeclaration.hpp"
#include "io/xml/XmlAttribute.hpp"
#include "io/xml/XmlParser.hpp"
#include "io/File.hpp"
#include "io/FileOutputStream.hpp"
#include "io/FilePathSeparator.hpp"
#include "io/FilePathSeparatorMatch.hpp"
#include "io/FileReader.hpp"
#include "io/FileWriter.hpp"
#include "io/IReader.hpp"
#include "io/IStorable.hpp"
#include "io/IWriter.hpp"
#include "io/NewLine.hpp"
#include "io/StorableFile.hpp"
#include "io/StandardOutputWriter.hpp"
#include "io/kv/KvPair.hpp"
#include "io/kv/KvDocument.hpp"
#include "io/kv/KvParser.hpp"
#include "io/kv/KvFileReader.hpp"

#include "logic/State.hpp"
#include "logic/StateConnection.hpp"
#include "logic/StateMachine.hpp"
#include "logic/StateMachineTypes.hpp"

#include "serialization/json/logic/SerializableJsonState.hpp"
#include "serialization/json/logic/SerializableJsonStateConnection.hpp"
#include "serialization/json/logic/SerializableJsonStateMachine.hpp"
#include "serialization/json/event/SerializableJsonEvent.hpp"
#include "serialization/ISerializable.hpp"

#include "time/Date.hpp"

#include "utils/RegexUtils.hpp"
#include "utils/STLUtils.hpp"

#if _WIN32
#include "utils/WindowsUtils.hpp"
#endif

#include "event/Event.hpp"
#include "event/EventTypes.hpp"
#include "event/EventHandler.hpp"
#include "event/IEventSubscriber.hpp"
#include "event/EventManager.hpp"

#include "factory/IFactory.hpp"

#endif
