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

#include "serialization/boxing/SerializableJSONBoolean.hpp"
#include "serialization/boxing/SerializableJSONDouble.hpp"
#include "serialization/boxing/SerializableJSONFloat.hpp"
#include "serialization/boxing/SerializableJSONInteger.hpp"
#include "serialization/boxing/SerializableJSONLong.hpp"
#include "serialization/boxing/SerializableJSONString.hpp"
#include "serialization/logic/SerializableJSONState.hpp"
#include "serialization/logic/SerializableJSONStateConnection.hpp"
#include "serialization/logic/SerializableJSONStateMachine.hpp"
#include "serialization/ISerializable.hpp"

#include "time/Date.hpp"

#include "utils/RegexUtils.hpp"
#include "utils/STLUtils.hpp"

#endif