/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-01-03
 *
 * */

#include <ls_std/encoding/base64/Base64.hpp>

std::string ls_std::Base64::encode(const std::string &_sequence)
{
  std::string encodedString, subSequence{};

  for(size_t index = 0 ; index < _sequence.size() ; index += 3)
  {
    subSequence = ls_std::Base64::_getSubSequence(_sequence, index);
    encodedString +=
  }

  return encodedString;
}

std::string ls_std::Base64::decode(const std::string &_sequence)
{
  return "";
}

std::string ls_std::Base64::_getSubSequence(const std::string &_sequence, size_t index)
{
  std::string subSequence{_sequence[index]};
  size_t size = _sequence.size();

  if((index + 1) < size)
  {
    subSequence += (_sequence[size+1]);
  }

  if((index + 2) < size)
  {
    subSequence += (_sequence[size+2]);
  }

  return subSequence;
}
