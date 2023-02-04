/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2023-02-04
 *
 * */

#include <bitset>
#include <ls-std/encoding/Base64.hpp>

ls::std::encoding::Base64::Base64() = default;

ls::std::encoding::Base64::~Base64() = default;

::std::string ls::std::encoding::Base64::encode(const ::std::string &_sequence)
{
  ::std::string encodedString{};

  for(size_t index = 0 ; index < _sequence.size() ; index += 3)
  {
    ::std::string byteTriple = ls::std::encoding::Base64::_getNextByteTriple(_sequence, index);
    encodedString += ls::std::encoding::Base64::_encodeByteTriple(byteTriple);
  }

  return ls::std::encoding::Base64::_applyEndingRule(encodedString, _sequence.size());
}

::std::string ls::std::encoding::Base64::decode(const ::std::string &_sequence)
{
  ::std::string decodedString{};

  for (int index{} ; index < _sequence.size() ; index += 4)
  {
    ::std::string quadruple = ls::std::encoding::Base64::_getNextByteQuadruple(_sequence, index);
    decodedString += ls::std::encoding::Base64::_decodeByteQuadruple(quadruple);
  }

  return decodedString;
}

::std::string ls::std::encoding::Base64::_applyEndingRule(::std::string _encodedString, size_t _sequenceSize)
{
  size_t size = _encodedString.size();

  if (_sequenceSize % 3 == 1)
  {
    _encodedString[size - 2] = '=';
    _encodedString[size - 1] = '=';
  }

  if (_sequenceSize % 3 == 2)
  {
    _encodedString[size - 1] = '=';
  }

  return _encodedString;
}

::std::string ls::std::encoding::Base64::_decodeByteQuadruple(const ::std::string& _quadruple)
{
  ::std::string decodedText{};
  uint8_t shiftValue = 16;
  uint32_t bitStorage = ls::std::encoding::Base64::_toDecodingBitStorage(_quadruple);

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

::std::string ls::std::encoding::Base64::_encodeByteTriple(const ::std::string& _byteTriple)
{
  ::std::string encodedText{};
  uint32_t bitStorage = ls::std::encoding::Base64::_toEncodingBitStorage(_byteTriple);
  static ::std::vector<uint32_t> bitMaskStorage = {16515072, 258048, 4032, 63};
  static ::std::unordered_map<uint8_t, char> encodingMap = ls::std::encoding::Base64::_getEncodingMap();
  uint8_t shiftValue = 18;

  for (uint8_t bitMaskIndex = 0 ; bitMaskIndex < 4 ; bitMaskIndex++)
  {
    uint32_t extractedBitSequence = ls::std::encoding::Base64::_extractBitSequence(bitMaskStorage[bitMaskIndex], bitStorage);
    extractedBitSequence = extractedBitSequence >> shiftValue;
    encodedText += encodingMap[(uint8_t) extractedBitSequence];
    shiftValue -= 6;
  }

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

::std::unordered_map<char, uint8_t> ls::std::encoding::Base64::_getDecodingMap()
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

::std::unordered_map<uint8_t, char> ls::std::encoding::Base64::_getEncodingMap()
{
  static ::std::unordered_map<uint8_t, char> encodingMap =
  {
    {0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}, {5, 'F'}, {6, 'G'}, {7, 'H'},
    {8, 'I'}, {9, 'J'}, {10, 'K'}, {11, 'L'}, {12, 'M'}, {13, 'N'}, {14, 'O'}, {15, 'P'},
    {16, 'Q'}, {17, 'R'}, {18, 'S'}, {19, 'T'}, {20, 'U'}, {21, 'V'}, {22, 'W'}, {23, 'X'},
    {24, 'Y'}, {25, 'Z'}, {26, 'a'}, {27, 'b'}, {28, 'c'}, {29, 'd'}, {30, 'e'}, {31, 'f'},
    {32, 'g'}, {33, 'h'}, {34, 'i'}, {35, 'j'}, {36, 'k'}, {37, 'l'}, {38, 'm'}, {39, 'n'},
    {40, 'o'}, {41, 'p'}, {42, 'q'}, {43, 'r'}, {44, 's'}, {45, 't'}, {46, 'u'}, {47, 'v'},
    {48, 'w'}, {49, 'x'}, {50, 'y'}, {51, 'z'}, {52, '0'}, {53, '1'}, {54, '2'}, {55, '3'},
    {56, '4'}, {57, '5'}, {58, '6'}, {59, '7'}, {60, '8'}, {61, '9'}, {62, '+'}, {63, '/'},
  };

  return encodingMap;
}

::std::string ls::std::encoding::Base64::_getNextByteQuadruple(const ::std::string &_sequence, size_t _index)
{
  return _sequence.substr(_index, 4);
}

::std::string ls::std::encoding::Base64::_getNextByteTriple(const ::std::string &_sequence, size_t _index)
{
  return _sequence.substr(_index, 3);
}

void ls::std::encoding::Base64::_mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask)
{
  _bitStorage = _bitStorage | _bitMask;
}

uint32_t ls::std::encoding::Base64::_toDecodingBitStorage(const ::std::string &_quadruple)
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

uint32_t ls::std::encoding::Base64::_toEncodingBitStorage(const ::std::string &_triple)
{
  uint32_t bitStorage{};
  uint8_t shiftValue = 16;

  for(char letter : _triple)
  {
    uint32_t bitMask = ls::std::encoding::Base64::_generateBitMask((uint8_t) letter, shiftValue);
    ls::std::encoding::Base64::_mergeBitSequence(bitStorage, bitMask);
    shiftValue -= 8;
  }

  return bitStorage;
}
