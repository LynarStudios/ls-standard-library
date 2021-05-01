/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2021-04-24
 *
 * */

#ifndef LS_STD_VERSION_HPP
#define LS_STD_VERSION_HPP

#include "Class.hpp"
#include <ls_std/serialization/ISerializable.hpp>
#include "Types.hpp"

namespace ls_std
{
  class Version : public ls_std::ISerializable
  {
    public:

      explicit Version(ls_std::version_type _majorVersion, ls_std::version_type _minorVersion, ls_std::version_type _patchVersion);
      ~Version() = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // other functionality

      ls_std::version_type getMajorVersion() const;
      ls_std::version_type getMinorVersion() const;
      ls_std::version_type getPatchVersion() const;
      static bool isValid(const std::string &_versionString);
      void setMajorVersion(ls_std::version_type _major);
      void setMinorVersion(ls_std::version_type _minor);
      void setPatchVersion(ls_std::version_type _patch);

    private:

      ls_std::version_type majorVersion{};
      ls_std::version_type minorVersion{};
      ls_std::version_type patchVersion{};

      static bool _isValid(const std::string &_versionString);
  };
}

#endif
