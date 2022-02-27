/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-02-27
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
  std::string decodedString{};

  for (int index{} ; index < _sequence.size() ; index += 4)
  {
    std::string quadruple = ls_std::Base64::_getNextByteQuadruple(_sequence, index);
    decodedString += ls_std::Base64::_decodeByteQuadruple(quadruple);
  }

  return decodedString;
}

std::string ls_std::Base64::_decodeByteQuadruple(const std::string& _quadruple)
{
  std::string decodedText{};
  uint8_t shiftValue = 16;
  uint32_t bitStorage = ls_std::Base64::_toBitStorage(_quadruple);

  for (uint8_t index = 0; index < ((uint8_t) _quadruple.size() - 1); index++)
  {
    uint32_t bitMask = ls_std::Base64::_generateBitMask(255, shiftValue);
    uint32_t bitSequence = ls_std::Base64::_extractBitSequence(bitMask, bitStorage);
    bitSequence = bitSequence >> shiftValue;

    decodedText += (char) bitSequence;
    shiftValue -= 8;
  }

  return decodedText;
}

uint8_t ls_std::Base64::_detectInitialShiftNumber(size_t size)
{
  return size * 8 - 6;
}

uint32_t ls_std::Base64::_extractBitSequence(uint32_t _bitMask, uint32_t _bitStorage)
{
  return _bitStorage & _bitMask;
}

uint32_t ls_std::Base64::_generateBitMask(uint32_t _maskValue, uint8_t _shiftValue)
{
  if(_shiftValue == 0)
  {
    return _maskValue;
  }

  if(_shiftValue < 0)
  {
    return _maskValue >> _shiftValue;
  }

  return _maskValue << _shiftValue;
}

std::string ls_std::Base64::_getEncodingFromBitSequence(uint32_t bitSequence, size_t characterSequenceSize)
{
  std::string encodedString{};
  uint8_t shiftByBits = ls_std::Base64::_detectInitialShiftNumber(characterSequenceSize);
  uint32_t buffer;

  for (uint8_t index = 0 ; index < 3 ; index++)
  {
    buffer = bitSequence >> shiftByBits;
    encodedString += this->_getCharacterFromLookUpTable((uint8_t) buffer);
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

char ls_std::Base64::_getCharacterFromLookUpTable(uint8_t byteBuffer)
{
  std::bitset<8> bitSequence{byteBuffer};
  bitSequence.set(6, false);
  bitSequence.set(7, false);

  return this->encodingTable[bitSequence.to_ulong()];
}

std::unordered_map<char, uint8_t> ls_std::Base64::_getDecodingMap()
{
  static std::unordered_map<char, uint8_t> decodingMap =
      {
          {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7},
          {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15},
          {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23},
          {'Y', 24}, {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29}, {'e', 30}, {'f', 31},
          {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39},
          {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47},
          {'w', 48}, {'x', 49}, {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54}, {'3', 55},
          {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59}, {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}
      };

  return decodingMap;
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

void ls_std::Base64::_mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask)
{
  _bitStorage = _bitStorage | _bitMask;
}

uint32_t ls_std::Base64::_toBitStorage(const std::string &_quadruple)
{
  uint32_t bitStorage{};
  uint8_t letterCounter = 1;
  std::unordered_map<char, uint8_t> decodingMap = ls_std::Base64::_getDecodingMap();

  for(char letter : _quadruple)
  {
    uint32_t bitMask = ls_std::Base64::_generateBitMask(decodingMap[(char) letter], (4 - letterCounter) * 6); // must be hardcoded - even in case of less than 4 characters, so that conversion is correct
    ls_std::Base64::_mergeBitSequence(bitStorage, bitMask);
    ++letterCounter;
  }

  return bitStorage;
}
