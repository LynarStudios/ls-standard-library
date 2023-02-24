/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/Version.hpp>
#include <regex>

using ls::std::core::Version;
using ls::std::core::type::byte_field;
using ls::std::core::type::version_type;
using std::regex;
using std::regex_match;
using std::stoi;
using std::string;
using std::to_string;

Version::Version(version_type _majorVersion, version_type _minorVersion, version_type _patchVersion) : majorVersion(_majorVersion), minorVersion(_minorVersion), patchVersion(_patchVersion)
{}

Version::~Version() noexcept = default;

byte_field Version::marshal()
{
  byte_field data{};

  data += to_string(this->majorVersion) + ".";
  data += to_string(this->minorVersion) + ".";
  data += to_string(this->patchVersion);

  return data;
}

void Version::unmarshal(const byte_field &_data)
{
  string field = _data;

  if (Version::_isValid(_data))
  {
    size_t position = field.find('.');
    string subSequence = field.substr(0, position);
    this->majorVersion = stoi(subSequence);
    field.erase(0, position + 1);

    position = field.find('.');
    subSequence = field.substr(0, position);
    this->minorVersion = stoi(subSequence);
    field.erase(0, position + 1);

    this->patchVersion = stoi(field);
  }
}

version_type Version::getMajorVersion() const
{
  return this->majorVersion;
}

version_type Version::getMinorVersion() const
{
  return this->minorVersion;
}

version_type Version::getPatchVersion() const
{
  return this->patchVersion;
}

bool Version::isValid(const string &_versionString)
{
  return Version::_isValid(_versionString);
}

void Version::setMajorVersion(version_type _major)
{
  this->majorVersion = _major;
}

void Version::setMinorVersion(version_type _minor)
{
  this->minorVersion = _minor;
}

void Version::setPatchVersion(version_type _patch)
{
  this->patchVersion = _patch;
}

bool Version::_isValid(const string &_versionString)
{
  bool isValidVersionString{};
  static regex versionRegex{R"(\d+[.]\d+[.]\d+)"};

  if (!_versionString.empty())
  {
    isValidVersionString = regex_match(_versionString.begin(), _versionString.end(), versionRegex);
  }

  return isValidVersionString;
}
