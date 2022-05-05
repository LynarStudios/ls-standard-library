/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_VERSION_HPP
#define LS_STD_VERSION_HPP

#include "Class.hpp"
#include <ls_std/serialization/ISerializable.hpp>
#include "Types.hpp"

namespace ls
{
  class Version : public ls::ISerializable
  {
    public:

      explicit Version(ls::version_type _majorVersion, ls::version_type _minorVersion, ls::version_type _patchVersion);
      ~Version() = default;

      // implementation

      ls::byte_field marshal() override;
      void unmarshal(const ls::byte_field &_data) override;

      // other functionality

      ls::version_type getMajorVersion() const;
      ls::version_type getMinorVersion() const;
      ls::version_type getPatchVersion() const;
      static bool isValid(const std::string &_versionString);
      void setMajorVersion(ls::version_type _major);
      void setMinorVersion(ls::version_type _minor);
      void setPatchVersion(ls::version_type _patch);

    private:

      ls::version_type majorVersion{};
      ls::version_type minorVersion{};
      ls::version_type patchVersion{};

      static bool _isValid(const std::string &_versionString);
  };
}

#endif
