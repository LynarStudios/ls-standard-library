/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2020-09-29
 *
 * */

#include <regex>
#include "Version.hpp"

ls_std::Version::Version(version_type _majorVersion, version_type _minorVersion, version_type _patchVersion) :
majorVersion(_majorVersion),
minorVersion(_minorVersion),
patchVersion(_patchVersion)
{}

ls_std::byte_field ls_std::Version::marshal()
{
  ls_std::byte_field data {};

  data += std::to_string(this->majorVersion) + ".";
  data += std::to_string(this->minorVersion) + ".";
  data += std::to_string(this->patchVersion);

  return data;
}

void ls_std::Version::unmarshal(const ls_std::byte_field &_data)
{
  std::string field = _data;
  std::string subSequence {};
  size_t position;

  if(ls_std::Version::_isValid(_data)) {
    position = field.find('.');
    subSequence = field.substr(0, position);
    this->majorVersion = std::stoi(subSequence);
    field.erase(0, position + 1);

    position = field.find('.');
    subSequence = field.substr(0, position);
    this->minorVersion = std::stoi(subSequence);
    field.erase(0, position + 1);

    this->patchVersion = std::stoi(field);
  }
}

ls_std::version_type ls_std::Version::getMajorVersion() const
{
  return this->majorVersion;
}

ls_std::version_type ls_std::Version::getMinorVersion() const
{
  return this->minorVersion;
}

ls_std::version_type ls_std::Version::getPatchVersion() const
{
  return this->patchVersion;
}

bool ls_std::Version::isValid(const std::string &_versionString)
{
  return ls_std::Version::_isValid(_versionString);
}

void ls_std::Version::setMajorVersion(version_type _major)
{
  this->majorVersion = _major;
}

void ls_std::Version::setMinorVersion(version_type _minor)
{
  this->minorVersion = _minor;
}

void ls_std::Version::setPatchVersion(version_type _patch)
{
  this->patchVersion = _patch;
}

bool ls_std::Version::_isValid(const std::string &_versionString)
{
  static std::regex versionRegex {R"(\d+[.]\d+[.]\d+)"};
  return std::regex_match(_versionString.begin(), _versionString.end(), versionRegex);
}
