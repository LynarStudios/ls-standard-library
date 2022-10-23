/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2022-10-23
 *
 * */

#ifndef LS_STD_VERSION_HPP
#define LS_STD_VERSION_HPP

#include "Class.hpp"
#include <ls_std/core/interface/ISerializable.hpp>
#include <ls_std/core/types/Types.hpp>
#include <ls_std/os/library/goals/dynamic_goal.hpp>

namespace ls::std::core
{
  class LS_STD_DYNAMIC_GOAL Version : public ls::std::core::interface_type::ISerializable
  {
    public:

      explicit Version(ls::std::core::type::version_type _majorVersion, ls::std::core::type::version_type _minorVersion, ls::std::core::type::version_type _patchVersion);
      ~Version() = default;

      // implementation

      ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

      // other functionality

      [[nodiscard]] ls::std::core::type::version_type getMajorVersion() const;
      [[nodiscard]] ls::std::core::type::version_type getMinorVersion() const;
      [[nodiscard]] ls::std::core::type::version_type getPatchVersion() const;
      static bool isValid(const ::std::string &_versionString);
      void setMajorVersion(ls::std::core::type::version_type _major);
      void setMinorVersion(ls::std::core::type::version_type _minor);
      void setPatchVersion(ls::std::core::type::version_type _patch);

    private:

      ls::std::core::type::version_type majorVersion{};
      ls::std::core::type::version_type minorVersion{};
      ls::std::core::type::version_type patchVersion{};

      static bool _isValid(const ::std::string &_versionString);
  };
}

#endif
