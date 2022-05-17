/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-05-17
 *
 * */

#include <ls_std/encoding/Base64.hpp>
#include <bitset>

std::string ls::std::encoding::Base64::encode(const ::std::string &_sequence)
{
  ::std::string encodedString{};

  for(size_t index = 0 ; index < _sequence.size() ; index += 3)
  {
    ::std::string byteTriple = ls::std::encoding::Base64::_getNextByteTriple(_sequence, index);
    encodedString += ls::std::encoding::Base64::_encodeByteTriple(byteTriple);
  }

  return encodedString;
}

std::string ls::std::encoding::Base64::decode(const ::std::string &_sequence)
{
  ::std::string decodedString{};

  for (int index{} ; index < _sequence.size() ; index += 4)
  {
    ::std::string quadruple = ls::std::encoding::Base64::_getNextByteQuadruple(_sequence, index);
    decodedString += ls::std::encoding::Base64::_decodeByteQuadruple(quadruple);
  }

  return decodedString;
}

std::string ls::std::encoding::Base64::_decodeByteQuadruple(const ::std::string& _quadruple)
{
  ::std::string decodedText{};
  uint8_t shiftValue = 16;
  uint32_t bitStorage = ls::std::encoding::Base64::_toBitStorage(_quadruple);

  for (uint8_t index = 0; index < ((uint8_t) _quadruple.size() - 1); index++)
  {
    uint32_t bitMask = ls::std::encoding::Base64::_generateBitMask(255, shiftValue);
    uint32_t bitSequence = ls::std::encoding::Base64::_extractBitSequence(bitMask, bitStorage);
    bitSequence = bitSequence >> shiftValue;

    decodedText += (char) bitSequence;
    shiftValue -= 8;
  }

  return decodedText;
}

std::string ls::std::encoding::Base64::_encodeByteTriple(const ::std::string& characterSequence)
{
  ::std::string encodedText{};

  return encodedText;
}

uint32_t ls::std::encoding::Base64::_extractBitSequence(uint32_t _bitMask, uint32_t _bitStorage)
{
  return _bitStorage & _bitMask;
}

uint32_t ls::std::encoding::Base64::_generateBitMask(uint32_t _maskValue, uint8_t _shiftValue)
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

std::unordered_map<char, uint8_t> ls::std::encoding::Base64::_getDecodingMap()
{
  static ::std::unordered_map<char, uint8_t> decodingMap =
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

std::vector<char> ls::std::encoding::Base64::_getEncodingField()
{
  static ::std::vector<char> encodingTable
  {
    'A','B','C','D','E','F','G','H',
    'I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X',
    'Y','Z','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3',
    '4','5','6','7','8','9','+','/'
  };

  return encodingTable;
}

std::string ls::std::encoding::Base64::_getNextByteQuadruple(const ::std::string &_sequence, size_t _index)
{
  return _sequence.substr(_index, 4);
}

std::string ls::std::encoding::Base64::_getNextByteTriple(const ::std::string &_sequence, size_t _index)
{
  return _sequence.substr(_index, 3);
}

void ls::std::encoding::Base64::_mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask)
{
  _bitStorage = _bitStorage | _bitMask;
}

uint32_t ls::std::encoding::Base64::_toBitStorage(const ::std::string &_quadruple)
{
  uint32_t bitStorage{};
  uint8_t letterCounter = 1;
  ::std::unordered_map<char, uint8_t> decodingMap = ls::std::encoding::Base64::_getDecodingMap();

  for(char letter : _quadruple)
  {
    uint32_t bitMask = ls::std::encoding::Base64::_generateBitMask(decodingMap[(char) letter], (4 - letterCounter) * 6); // must be hardcoded - even in case of less than 4 characters, so that conversion is correct
    ls::std::encoding::Base64::_mergeBitSequence(bitStorage, bitMask);
    ++letterCounter;
  }

  return bitStorage;
}
