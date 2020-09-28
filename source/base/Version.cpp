/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2020-09-28
 *
 * */

#include "Version.hpp"

ls_std::Version::Version(version_type _major, version_type _minor, version_type _patch) :
major(_major),
minor(_minor),
patch(_patch)
{}

ls_std::byte_field ls_std::Version::marshal()
{
  ls_std::byte_field data {};

  data += std::to_string(this->major) + ".";
  data += std::to_string(this->minor) + ".";
  data += std::to_string(this->patch);

  return data;
}

void ls_std::Version::unmarshal(const ls_std::byte_field &_data)
{

}

ls_std::version_type ls_std::Version::getMajor() const
{
  return this->major;
}

ls_std::version_type ls_std::Version::getMinor() const
{
  return this->minor;
}
