/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-02-27
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

      static std::string _decodeByteQuadruple(const std::string& _quadruple);
      static uint8_t _detectInitialShiftNumber(size_t size);
      static uint32_t _generateBitMask(uint32_t _maskValue, uint8_t _shiftValue);
      std::string _getEncodingFromBitSequence(uint32_t bitSequence, size_t characterSequenceSize);
      static uint32_t _getBitSequenceFromCharacterSequence(const std::string &basicString);
      char _getCharacterFromLookUpTable(uint8_t byteBuffer);
      std::string _getEncodingFromByteTriple(const std::string& characterSequence);
      static std::string _getNextByteTriple(const std::string& _sequence, size_t _index);
      static std::string _getNextByteQuadruple(const std::string &_sequence, size_t _index);
      static uint32_t _extractBitSequence(uint32_t _bitMask, uint32_t _bitStorage);
      static void _mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask);
      static uint32_t _toBitStorage(const std::string &_quadruple);
      static std::unordered_map<char, uint8_t> _getDecodingMap();
  };
}

#endif
