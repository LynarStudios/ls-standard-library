/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-01-03
 * Changed:         2022-10-23
 *
 * */

#ifndef LS_STD_BASE64_HPP
#define LS_STD_BASE64_HPP

#include <ls_std/core/interface/IEncoding.hpp>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <ls_std/os/library/goals/dynamic_goal.hpp>

namespace ls::std::encoding
{
  class LS_STD_DYNAMIC_GOAL Base64 : public ls::std::core::interface_type::IEncoding
  {
    public:

      Base64() = default;
      ~Base64() = default;

      // implementation

      ::std::string encode(const ::std::string &_sequence) override;
      ::std::string decode(const ::std::string &_sequence) override;

    private:

      static ::std::string _applyEndingRule(::std::string _encodedString, size_t _sequenceSize);
      static ::std::string _decodeByteQuadruple(const ::std::string &_quadruple);
      static ::std::string _encodeByteTriple(const ::std::string &_byteTriple);
      static uint32_t _extractBitSequence(uint32_t _bitMask, uint32_t _bitStorage);
      static uint32_t _generateBitMask(uint32_t _maskValue, uint8_t _shiftValue);
      static ::std::unordered_map<char, uint8_t> _getDecodingMap();
      static ::std::unordered_map<uint8_t, char> _getEncodingMap();
      static ::std::string _getNextByteQuadruple(const ::std::string &_sequence, size_t _index);
      static ::std::string _getNextByteTriple(const ::std::string &_sequence, size_t _index);
      static void _mergeBitSequence(uint32_t &_bitStorage, const uint32_t &_bitMask);
      static uint32_t _toDecodingBitStorage(const ::std::string &_quadruple);
      static uint32_t _toEncodingBitStorage(const ::std::string &_triple);
  };
}

#endif
