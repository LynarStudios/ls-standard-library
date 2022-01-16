/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-01-16
 *
 * */

#ifndef LS_STD_BASE64_HPP
#define LS_STD_BASE64_HPP

#include <ls_std/encoding/IEncoding.hpp>
#include <bitset>
#include <vector>

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

      const std::vector<char> table
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
      std::string _getEncodingFromCharacterSequence(const std::string& characterSequence);
      static std::string _getNextByteTriple(const std::string& _sequence, size_t index);
  };
}

#endif
