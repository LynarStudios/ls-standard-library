/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_BASE64_HPP
#define LS_STD_BASE64_HPP

#include <bitset>
#include <ls-std/core/interface/IEncoding.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <unordered_map>
#include <vector>

namespace ls::std::encoding
{
  class LS_STD_DYNAMIC_GOAL Base64 : public ls::std::core::interface_type::IEncoding
  {
    public:

      Base64();
      ~Base64() override;

      // implementation

      [[nodiscard]] ::std::string encode(const ::std::string &_sequence) override;
      [[nodiscard]] ::std::string decode(const ::std::string &_sequence) override;

    private:

      [[nodiscard]] static ::std::string _applyEndingRule(::std::string _encodedString, size_t _sequenceSize);
      [[nodiscard]] static ::std::string _decodeByteQuadruple(const ::std::string &_quadruple);
      [[nodiscard]] static ::std::string _encodeByteTriple(const ::std::string &_byteTriple);
      [[nodiscard]] static uint32_t _extractBitSequence(uint32_t _bitMask, uint32_t _bitStorage);
      [[nodiscard]] static uint32_t _generateBitMask(uint32_t _maskValue, uint8_t _shiftValue);
      [[nodiscard]] static ::std::unordered_map<char, uint8_t> _getDecodingMap();
      [[nodiscard]] static ::std::unordered_map<uint8_t, char> _getEncodingMap();
      [[nodiscard]] static ::std::string _getNextByteQuadruple(const ::std::string &_sequence, size_t _index);
      [[nodiscard]] static ::std::string _getNextByteTriple(const ::std::string &_sequence, size_t _index);
      static void _mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask);
      [[nodiscard]] static uint32_t _toDecodingBitStorage(const ::std::string &_quadruple);
      [[nodiscard]] static uint32_t _toEncodingBitStorage(const ::std::string &_triple);
  };
}

#endif
