/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-04-07
* Changed:         2023-04-07
*
* */

#ifndef LS_STD_JNI_API_HPP
#define LS_STD_JNI_API_HPP

#include <ls-std/core/interface/IJniApi.hpp>
#include <ls-std/os/dynamic-goal.hpp>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL JniApi : public ls::std::core::interface_type::IJniApi
  {
    public:

      explicit JniApi(JNIEnv *_environment);
      ~JniApi() noexcept override;

      jclass findClass(const ::std::string &_classPath) override;

    private:

      JNIEnv *environment{};
  };
}

#endif
