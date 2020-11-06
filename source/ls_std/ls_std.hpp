/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-29
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_LS_STD_HPP
#define LS_STD_LS_STD_HPP

#include "../../include/ls_std/base/Class.hpp"
#include "../../include/ls_std/base/Types.hpp"
#include "../../include/ls_std/base/Version.hpp"

#include "../../include/ls_std/boxing/IBoxing.hpp"
#include "../../include/ls_std/boxing/Boolean.hpp"
#include "../../include/ls_std/boxing/Double.hpp"
#include "../../include/ls_std/boxing/Float.hpp"
#include "../../include/ls_std/boxing/Integer.hpp"
#include "../../include/ls_std/boxing/Long.hpp"
#include "../../include/ls_std/boxing/String.hpp"

#include "exception/FileNotFoundException.hpp"
#include "exception/FileOperationException.hpp"
#include "exception/IllegalArgumentException.hpp"
#include "exception/IllegalArithmeticOperationException.hpp"

#include "io/logging/LogLevel.hpp"
#include "io/logging/LogLevelValue.hpp"
#include "io/logging/Logger.hpp"
#include "io/xml/XMLReaderMock.hpp"
#include "io/xml/XMLReader.hpp"
#include "io/xml/XMLParseMode.hpp"
#include "io/xml/XMLParseData.hpp"
#include "io/xml/XMLNode.hpp"
#include "io/xml/XMLDocument.hpp"
#include "io/xml/XMLDeclaration.hpp"
#include "io/xml/XMLAttribute.hpp"
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
#include "serialization/ISerializable.hpp"

#include "time/Date.hpp"

#include "utils/RegexUtils.hpp"
#include "utils/STLUtils.hpp"

#endif
