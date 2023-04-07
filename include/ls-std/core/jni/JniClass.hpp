/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
*
* */

#ifndef LS_STD_JNI_CLASS_HPP
#define LS_STD_JNI_CLASS_HPP

#include "JniClassParameter.hpp"
#include <jni.h>
#include <ls-std/core/interface/IJniApi.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>
#include <unordered_map>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL JniClass
  {
    public:

      explicit JniClass(const ::std::shared_ptr<ls::std::core::JniClassParameter> &_parameter, const ::std::string &_path);
      virtual ~JniClass();

      [[nodiscard]] bool hasMethod(const ::std::string &_methodIdentifier);
      bool load();                                                                                    // nodiscard is optional here
      bool loadMethod(const ::std::string &_methodIdentifier, const ::std::string &_methodSignature); // nodiscard is optional here

    private:

      jclass javaClass{};
      ::std::unordered_map<::std::string, jmethodID> methods{};
      ::std::shared_ptr<ls::std::core::JniClassParameter> parameter{};
      ::std::string path{};

      void _createJniApi();
      [[nodiscard]] bool _hasMethod(const ::std::string &_methodIdentifier);
  };
}

#endif
