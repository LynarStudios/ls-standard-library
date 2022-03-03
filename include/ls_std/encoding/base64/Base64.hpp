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

      static std::string _decodeByteQuadruple(const std::string& _quadruple);
      std::string _encodeByteTriple(const std::string& characterSequence);
      static uint32_t _extractBitSequence(uint32_t _bitMask, uint32_t _bitStorage);
      static uint32_t _generateBitMask(uint32_t _maskValue, uint8_t _shiftValue);
      static std::unordered_map<char, uint8_t> _getDecodingMap();
      static std::vector<char> _getEncodingField();
      static std::string _getNextByteQuadruple(const std::string &_sequence, size_t _index);
      static std::string _getNextByteTriple(const std::string& _sequence, size_t _index);
      static void _mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask);
      static uint32_t _toBitStorage(const std::string &_quadruple);
  };
}

#endif
