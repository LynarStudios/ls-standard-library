/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-02-06
 *
 * */

#include <ls_std/encoding/base64/Base64.hpp>
#include <bitset>

std::string ls_std::Base64::encode(const std::string &_sequence)
{
  std::string encodedString, byteTriple{};

  for(size_t index = 0 ; index < _sequence.size() ; index += 3)
  {
    byteTriple = ls_std::Base64::_getNextByteTriple(_sequence, index);
    encodedString += ls_std::Base64::_getEncodingFromByteTriple(byteTriple);
  }

  return encodedString;
}

std::string ls_std::Base64::decode(const std::string &_sequence)
{
  std::string decodedString, byteQuadruple{};

  for(size_t index = 0 ; index < byteQuadruple.size() ; index += 4)
  {
    byteQuadruple = ls_std::Base64::_getNextByteQuadruple(_sequence, index);
    decodedString += ls_std::Base64::_getDecodingFromByteQuadruple(byteQuadruple);
  }

  return decodedString;
}

uint8_t ls_std::Base64::_detectInitialShiftNumber(size_t size)
{
  return size * 8 - 6;
}

std::string ls_std::Base64::_getEncodingFromBitSequence(uint32_t bitSequence, size_t characterSequenceSize)
{
  std::string encodedString{};
  uint8_t shiftByBits = ls_std::Base64::_detectInitialShiftNumber(characterSequenceSize);
  uint32_t buffer;

  for (uint8_t index = 0 ; index < 3 ; index++)
  {
    buffer = bitSequence >> shiftByBits;
    encodedString += this->_getCharacterFromLookUpTable((uint8_t) buffer, shiftByBits);
    shiftByBits -= 6;
  }

  return encodedString;
}

uint32_t ls_std::Base64::_getBitSequenceFromCharacterSequence(const std::string &basicString)
{
  uint32_t bits{};

  for (const char &letter : basicString)
  {
    bits = bits | (uint8_t) letter;
    bits = bits << 8;
  }

  bits = bits >> 8;
  return bits;
}

char ls_std::Base64::_getCharacterFromLookUpTable(uint8_t byteBuffer, uint8_t shiftByBits)
{
  std::bitset<8> bitSequence{byteBuffer};
  bitSequence.set(6, false);
  bitSequence.set(7, false);

  return this->encodingTable[bitSequence.to_ulong()];
}

std::string ls_std::Base64::_getEncodingFromByteTriple(const std::string& characterSequence)
{
  uint32_t bitSequence = ls_std::Base64::_getBitSequenceFromCharacterSequence(characterSequence);
  std::string encodingString = this->_getEncodingFromBitSequence(bitSequence, characterSequence.size());

  return encodingString;
}

std::string ls_std::Base64::_getNextByteTriple(const std::string &_sequence, size_t _index)
{
  return _sequence.substr(_index, 3);
}

std::string ls_std::Base64::_getNextByteQuadruple(const std::string &_sequence, size_t _index)
{
  return _sequence.substr(_index, 4);
}

std::string ls_std::Base64::_getDecodingFromByteQuadruple(std::string _byteQuadruple)
{


  return std::string();
}
