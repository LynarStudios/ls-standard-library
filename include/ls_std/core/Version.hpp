/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-27
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_VERSION_HPP
#define LS_STD_VERSION_HPP

#include "Class.hpp"
#include <ls_std/serialization/ISerializable.hpp>
#include "Types.hpp"

namespace ls
{
  namespace std
  {
    namespace core
    {
      class Version : public ls::ISerializable
      {
        public:

          explicit Version(ls::std::core::version_type _majorVersion, ls::std::core::version_type _minorVersion, ls::std::core::version_type _patchVersion);
          ~Version() = default;

          // implementation

          ls::std::core::byte_field marshal() override;
          void unmarshal(const ls::std::core::byte_field &_data) override;

          // other functionality

          ls::std::core::version_type getMajorVersion() const;
          ls::std::core::version_type getMinorVersion() const;
          ls::std::core::version_type getPatchVersion() const;
          static bool isValid(const ::std::string &_versionString);
          void setMajorVersion(ls::std::core::version_type _major);
          void setMinorVersion(ls::std::core::version_type _minor);
          void setPatchVersion(ls::std::core::version_type _patch);

        private:

          ls::std::core::version_type majorVersion{};
          ls::std::core::version_type minorVersion{};
          ls::std::core::version_type patchVersion{};

          static bool _isValid(const ::std::string &_versionString);
      };
    }
  }
}

#endif
