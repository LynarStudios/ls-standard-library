/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2022-05-05
 *
 * */

#include <regex>
#include <ls_std/core/Version.hpp>

ls::Version::Version(ls::version_type _majorVersion, ls::version_type _minorVersion, ls::version_type _patchVersion)
    : majorVersion(_majorVersion),
      minorVersion(_minorVersion),
      patchVersion(_patchVersion)
{}

ls::byte_field ls::Version::marshal()
{
  ls::byte_field data{};

  data += std::to_string(this->majorVersion) + ".";
  data += std::to_string(this->minorVersion) + ".";
  data += std::to_string(this->patchVersion);

  return data;
}

void ls::Version::unmarshal(const ls::byte_field &_data)
{
  std::string field = _data;

  if (ls::Version::_isValid(_data))
  {
    size_t position = field.find('.');
    std::string subSequence = field.substr(0, position);
    this->majorVersion = std::stoi(subSequence);
    field.erase(0, position + 1);

    position = field.find('.');
    subSequence = field.substr(0, position);
    this->minorVersion = std::stoi(subSequence);
    field.erase(0, position + 1);

    this->patchVersion = std::stoi(field);
  }
}

ls::version_type ls::Version::getMajorVersion() const
{
  return this->majorVersion;
}

ls::version_type ls::Version::getMinorVersion() const
{
  return this->minorVersion;
}

ls::version_type ls::Version::getPatchVersion() const
{
  return this->patchVersion;
}

bool ls::Version::isValid(const std::string &_versionString)
{
  return ls::Version::_isValid(_versionString);
}

void ls::Version::setMajorVersion(ls::version_type _major)
{
  this->majorVersion = _major;
}

void ls::Version::setMinorVersion(ls::version_type _minor)
{
  this->minorVersion = _minor;
}

void ls::Version::setPatchVersion(ls::version_type _patch)
{
  this->patchVersion = _patch;
}

bool ls::Version::_isValid(const std::string &_versionString)
{
  bool isValidVersionString{};
  static std::regex versionRegex{R"(\d+[.]\d+[.]\d+)"};

  if (!_versionString.empty())
  {
    isValidVersionString = std::regex_match(_versionString.begin(), _versionString.end(), versionRegex);
  }

  return isValidVersionString;
}
