/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2020-09-29
 *
 * */

#ifndef LS_STD_VERSION_HPP
#define LS_STD_VERSION_HPP

#include "Class.hpp"
#include "../serialization/ISerializable.hpp"
#include "../base/Types.hpp"

namespace ls_std {
  class Version : public ISerializable {
    public:

      explicit Version(version_type _majorVersion, version_type _minorVersion, version_type _patchVersion);
      ~Version() = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // other functionality

      version_type getMajorVersion() const;
      version_type getMinorVersion() const;
      version_type getPatchVersion() const;
      static bool isValid(const std::string& _versionString);
      void setMajorVersion(version_type _major);
      void setMinorVersion(version_type _minor);
      void setPatchVersion(version_type _patch);

    private:

      version_type majorVersion {};
      version_type minorVersion {};
      version_type patchVersion {};

      static bool _isValid(const std::string& _versionString);
  };
}

#endif
