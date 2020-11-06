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

#include "../../include/ls_std/exception/FileNotFoundException.hpp"
#include "../../include/ls_std/exception/FileOperationException.hpp"
#include "../../include/ls_std/exception/IllegalArgumentException.hpp"
#include "../../include/ls_std/exception/IllegalArithmeticOperationException.hpp"

#include "../../include/ls_std/io/logging/LogLevel.hpp"
#include "../../include/ls_std/io/logging/LogLevelValue.hpp"
#include "../../include/ls_std/io/logging/Logger.hpp"
#include "../../include/ls_std/io/xml/XMLReaderMock.hpp"
#include "../../include/ls_std/io/xml/XMLReader.hpp"
#include "../../include/ls_std/io/xml/XMLParseMode.hpp"
#include "../../include/ls_std/io/xml/XMLParseData.hpp"
#include "../../include/ls_std/io/xml/XMLNode.hpp"
#include "../../include/ls_std/io/xml/XMLDocument.hpp"
#include "../../include/ls_std/io/xml/XMLDeclaration.hpp"
#include "../../include/ls_std/io/xml/XMLAttribute.hpp"
#include "../../include/ls_std/io/File.hpp"
#include "../../include/ls_std/io/FileOutputStream.hpp"
#include "../../include/ls_std/io/FilePathSeparator.hpp"
#include "../../include/ls_std/io/FilePathSeparatorMatch.hpp"
#include "../../include/ls_std/io/FileReader.hpp"
#include "../../include/ls_std/io/FileWriter.hpp"
#include "../../include/ls_std/io/IReader.hpp"
#include "../../include/ls_std/io/IStorable.hpp"
#include "../../include/ls_std/io/IWriter.hpp"
#include "../../include/ls_std/io/NewLine.hpp"
#include "../../include/ls_std/io/StorableFile.hpp"

#include "../../include/ls_std/logic/State.hpp"
#include "../../include/ls_std/logic/StateConnection.hpp"
#include "../../include/ls_std/logic/StateMachine.hpp"
#include "../../include/ls_std/logic/StateMachineTypes.hpp"

#include "../../include/ls_std/serialization/boxing/SerializableJSONBoolean.hpp"
#include "../../include/ls_std/serialization/boxing/SerializableJSONDouble.hpp"
#include "../../include/ls_std/serialization/boxing/SerializableJSONFloat.hpp"
#include "../../include/ls_std/serialization/boxing/SerializableJSONInteger.hpp"
#include "../../include/ls_std/serialization/boxing/SerializableJSONLong.hpp"
#include "../../include/ls_std/serialization/boxing/SerializableJSONString.hpp"
#include "../../include/ls_std/serialization/logic/SerializableJSONState.hpp"
#include "../../include/ls_std/serialization/logic/SerializableJSONStateConnection.hpp"
#include "../../include/ls_std/serialization/logic/SerializableJSONStateMachine.hpp"
#include "../../include/ls_std/serialization/ISerializable.hpp"

#include "../../include/ls_std/time/Date.hpp"

#include "../../include/ls_std/utils/RegexUtils.hpp"
#include "../../include/ls_std/utils/STLUtils.hpp"

#endif
