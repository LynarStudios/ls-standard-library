/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-29
 * Changed:         2021-05-01
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

#include "boxing/IBoxing.hpp"
#include "boxing/Boolean.hpp"
#include "boxing/Double.hpp"
#include "boxing/Float.hpp"
#include "boxing/Integer.hpp"
#include "boxing/Long.hpp"
#include "boxing/String.hpp"

#include "exception/FileNotFoundException.hpp"
#include "exception/FileOperationException.hpp"
#include "exception/IllegalArgumentException.hpp"
#include "exception/IllegalArithmeticOperationException.hpp"
#include "exception/IncompleteJsonException.hpp"
#include "exception/NullPointerException.hpp"

#include "io/logging/LogLevel.hpp"
#include "io/logging/LogLevelValue.hpp"
#include "io/logging/Logger.hpp"
#include "io/xml/XMLReader.hpp"
#include "io/xml/XMLParseMode.hpp"
#include "io/xml/XMLParseData.hpp"
#include "io/xml/XMLNode.hpp"
#include "io/xml/XMLDocument.hpp"
#include "io/xml/XMLDeclaration.hpp"
#include "io/xml/XMLAttribute.hpp"
#include "io/xml/XMLParser.hpp"
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
#include "io/kv/KVPair.hpp"
#include "io/kv/KVDocument.hpp"
#include "io/kv/KVParser.hpp"
#include "io/kv/KVReader.hpp"

#include "logic/State.hpp"
#include "logic/StateConnection.hpp"
#include "logic/StateMachine.hpp"
#include "logic/StateMachineTypes.hpp"

#include "serialization/json/boxing/SerializableJSONBoolean.hpp"
#include "serialization/json/boxing/SerializableJSONDouble.hpp"
#include "serialization/json/boxing/SerializableJSONFloat.hpp"
#include "serialization/json/boxing/SerializableJSONInteger.hpp"
#include "serialization/json/boxing/SerializableJSONLong.hpp"
#include "serialization/json/boxing/SerializableJSONString.hpp"
#include "serialization/json/logic/SerializableJSONState.hpp"
#include "serialization/json/logic/SerializableJSONStateConnection.hpp"
#include "serialization/json/logic/SerializableJSONStateMachine.hpp"
#include "serialization/json/event/SerializableJSONEvent.hpp"
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
#include "ls_std/factory/serialization/json/SerializableJSONFactory.hpp"
#include "factory/serialization/json/boxing/SerializableJSONBooleanFactory.hpp"
#include "factory/serialization/json/boxing/SerializableJSONDoubleFactory.hpp"
#include "factory/serialization/json/boxing/SerializableJSONFloatFactory.hpp"
#include "factory/serialization/json/boxing/SerializableJSONIntegerFactory.hpp"
#include "factory/serialization/json/boxing/SerializableJSONLongFactory.hpp"
#include "factory/serialization/json/boxing/SerializableJSONStringFactory.hpp"
#include "factory/serialization/json/event/SerializableJSONEventFactory.hpp"

#endif
