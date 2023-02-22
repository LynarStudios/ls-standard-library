/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2023-02-22
 *
 * */

#include <ls-std/core/Version.hpp>
#include <regex>

ls::std::core::Version::Version(ls::std::core::type::version_type _majorVersion, ls::std::core::type::version_type _minorVersion, ls::std::core::type::version_type _patchVersion) : majorVersion(_majorVersion), minorVersion(_minorVersion), patchVersion(_patchVersion)
{}

ls::std::core::Version::~Version() noexcept = default;

ls::std::core::type::byte_field ls::std::core::Version::marshal()
{
  ls::std::core::type::byte_field data{};

  data += ::std::to_string(this->majorVersion) + ".";
  data += ::std::to_string(this->minorVersion) + ".";
  data += ::std::to_string(this->patchVersion);

  return data;
}

void ls::std::core::Version::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ::std::string field = _data;

  if (ls::std::core::Version::_isValid(_data))
  {
    size_t position = field.find('.');
    ::std::string subSequence = field.substr(0, position);
    this->majorVersion = ::std::stoi(subSequence);
    field.erase(0, position + 1);

    position = field.find('.');
    subSequence = field.substr(0, position);
    this->minorVersion = ::std::stoi(subSequence);
    field.erase(0, position + 1);

    this->patchVersion = ::std::stoi(field);
  }
}

ls::std::core::type::version_type ls::std::core::Version::getMajorVersion() const
{
  return this->majorVersion;
}

ls::std::core::type::version_type ls::std::core::Version::getMinorVersion() const
{
  return this->minorVersion;
}

ls::std::core::type::version_type ls::std::core::Version::getPatchVersion() const
{
  return this->patchVersion;
}

bool ls::std::core::Version::isValid(const ::std::string &_versionString)
{
  return ls::std::core::Version::_isValid(_versionString);
}

void ls::std::core::Version::setMajorVersion(ls::std::core::type::version_type _major)
{
  this->majorVersion = _major;
}

void ls::std::core::Version::setMinorVersion(ls::std::core::type::version_type _minor)
{
  this->minorVersion = _minor;
}

void ls::std::core::Version::setPatchVersion(ls::std::core::type::version_type _patch)
{
  this->patchVersion = _patch;
}

bool ls::std::core::Version::_isValid(const ::std::string &_versionString)
{
  bool isValidVersionString{};
  static ::std::regex versionRegex{R"(\d+[.]\d+[.]\d+)"};

  if (!_versionString.empty())
  {
    isValidVersionString = ::std::regex_match(_versionString.begin(), _versionString.end(), versionRegex);
  }

  return isValidVersionString;
}
