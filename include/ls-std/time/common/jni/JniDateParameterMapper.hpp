/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-09
* Changed:         2023-04-10
*
* */

#ifndef LS_STD_JNI_DATE_PARAMETER_MAPPER_HPP
#define LS_STD_JNI_DATE_PARAMETER_MAPPER_HPP

#include <ls-std/core/jni/JniClass.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <ls-std/time/common/DateParameter.hpp>

namespace ls::std::time::experimental
{
  class LS_STD_DYNAMIC_GOAL JniDateParameterMapper
  {
    public:

      JniDateParameterMapper();
      ~JniDateParameterMapper();

      [[nodiscard]] static ls::std::time::DateParameter toDateParameter(const ls::std::core::experimental::JniClass &_javaClass);
  };
}

#endif
