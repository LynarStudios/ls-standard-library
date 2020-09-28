/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-28
 * Changed:         2020-09-28
 *
 * */

#include <regex>
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
  std::string field = _data;
  std::string subSequence {};
  size_t position;

  if(ls_std::Version::_isValid(_data)) {
    position = field.find('.');
    subSequence = field.substr(0, position);
    this->major = std::stoi(subSequence);
    field.erase(0, position + 1);

    position = field.find('.');
    subSequence = field.substr(0, position);
    this->minor = std::stoi(subSequence);
    field.erase(0, position + 1);

    this->patch = std::stoi(field);
  }
}

ls_std::version_type ls_std::Version::getMajor() const
{
  return this->major;
}

ls_std::version_type ls_std::Version::getMinor() const
{
  return this->minor;
}

ls_std::version_type ls_std::Version::getPatch() const
{
  return this->patch;
}

bool ls_std::Version::isValid(const std::string &_versionString)
{
  return ls_std::Version::_isValid(_versionString);
}

void ls_std::Version::setMajor(version_type _major)
{
  this->major = _major;
}

void ls_std::Version::setMinor(version_type _minor)
{
  this->minor = _minor;
}

void ls_std::Version::setPatch(version_type _patch)
{
  this->patch = _patch;
}

bool ls_std::Version::_isValid(const std::string &_versionString)
{
  static std::regex versionRegex {R"(\d+[.]\d+[.]\d+)"};
  return std::regex_match(_versionString.begin(), _versionString.end(), versionRegex);
}
