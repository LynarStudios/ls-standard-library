/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2020-09-27
 *
 * */

#ifndef LS_STD_VERSION_HPP
#define LS_STD_VERSION_HPP

#include "Class.hpp"
#include "../serialization/ISerializable.hpp"
#include "../base/Types.hpp"

namespace ls_std {
  class Version : public ISerializable {
      explicit Version(version_type _major, version_type _minor, version_type _patch);
      ~Version() = default;

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      version_type getMajor() const;
      version_type getMinor() const;
      version_type getPatch();
      void setMajor(version_type _major);
      void setMinor(version_type _minor);
      void setPatch(version_type _patch);

    private:

      version_type major {};
      version_type minor {};
      version_type patch {};

      bool _isValidVersionString(const std::string& _versionString);
  };
}

#endif
