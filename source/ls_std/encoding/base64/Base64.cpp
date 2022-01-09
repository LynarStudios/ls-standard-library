/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-01-08
 *
 * */

#include <ls_std/encoding/base64/Base64.hpp>
#include <bitset>
#include <sstream>

std::string ls_std::Base64::encode(const std::string &_sequence)
{
  std::string encodedString, subSequence{};

  for(size_t index = 0 ; index < _sequence.size() ; index += 3)
  {
    subSequence = ls_std::Base64::_getNextByteTriple(_sequence, index);
    encodedString += ls_std::Base64::_getEncodingFromSubSequence(subSequence);
  }

  return encodedString;
}

std::string ls_std::Base64::decode(const std::string &_sequence)
{
  return "";
}

std::bitset<24> ls_std::Base64::_getBitSequenceFromSequence(const std::string &basicString)
{
  uint32_t bits{};
  std::stringstream stringStream{basicString};
  stringStream >> bits;
  std::bitset<32> bitSequenceBuffer{bits};
  std::bitset<24> bitSequence{};

  return bitSequence;
}

std::string ls_std::Base64::_getEncodingFromSubSequence(const std::string& basicString)
{
  std::string encodingString{};
  std::bitset<24> bitSequence = ls_std::Base64::_getBitSequenceFromSequence(basicString);

  return encodingString;
}

std::string ls_std::Base64::_getNextByteTriple(const std::string &_sequence, size_t index)
{
  std::string subSequence{_sequence[index]};
  size_t size = _sequence.size();

  if((index + 1) < size)
  {
    subSequence += (_sequence[index+1]);
  }

  if((index + 2) < size)
  {
    subSequence += (_sequence[index+2]);
  }

  return subSequence;
}
