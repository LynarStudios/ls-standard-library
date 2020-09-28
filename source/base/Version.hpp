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
    public:

      explicit Version(version_type _major, version_type _minor, version_type _patch);
      ~Version() = default;

      // implementation

      ls_std::byte_field marshal() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // other functionality

      version_type getMajor() const;
      version_type getMinor() const;
      version_type getPatch() const;
      static bool isValid(const std::string& _versionString);
      void setMajor(version_type _major);
      void setMinor(version_type _minor);
      void setPatch(version_type _patch);

    private:

      version_type major {};
      version_type minor {};
      version_type patch {};

      static bool _isValid(const std::string& _versionString);
  };
}

#endif
