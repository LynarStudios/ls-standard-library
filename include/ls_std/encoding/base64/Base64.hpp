/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-02-06
 *
 * */

#ifndef LS_STD_BASE64_HPP
#define LS_STD_BASE64_HPP

#include <ls_std/encoding/IEncoding.hpp>
#include <bitset>
#include <vector>
#include <unordered_map>

namespace ls_std
{
  class Base64 : public ls_std::IEncoding
  {
    public:

      Base64() = default;
      ~Base64() = default;

      // implementation

      std::string encode(const std::string &_sequence) override;
      std::string decode(const std::string &_sequence) override;

    private:

      const std::unordered_map<char, uint8_t> decodingTable
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

      const std::vector<char> encodingTable
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

      static uint8_t _detectInitialShiftNumber(size_t size);
      std::string _getEncodingFromBitSequence(uint32_t bitSequence, size_t characterSequenceSize);
      static uint32_t _getBitSequenceFromCharacterSequence(const std::string &basicString);
      char _getCharacterFromLookUpTable(uint8_t byteBuffer, uint8_t shiftByBits);
      std::string _getEncodingFromByteTriple(const std::string& characterSequence);
      static std::string _getNextByteTriple(const std::string& _sequence, size_t _index);
      static std::string _getNextByteQuadruple(const std::string &_sequence, size_t _index);
      std::string _getDecodingFromByteQuadruple(std::string _byteQuadruple);
  };
}

#endif
