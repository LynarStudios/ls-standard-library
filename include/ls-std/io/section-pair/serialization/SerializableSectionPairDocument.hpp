/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-22
*
* */

#ifndef LS_STD_SERIALIZABLE_SECTION_PAIR_DOCUMENT_HPP
#define LS_STD_SERIALIZABLE_SECTION_PAIR_DOCUMENT_HPP

#include "SerializableSectionPairParameter.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/ISerializable.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL SerializableSectionPairDocument : public ls::std::core::interface_type::ISerializable, public ls::std::core::Class
  {
    public:

      explicit SerializableSectionPairDocument(const ls::std::io::SerializableSectionPairParameter &_parameter);
      ~SerializableSectionPairDocument() noexcept override;

      [[nodiscard]] ::std::shared_ptr<ls::std::core::Class> getValue();
      [[nodiscard]] ls::std::core::type::byte_field marshal() override;
      void unmarshal(const ls::std::core::type::byte_field &_data) override;

    private:

      ls::std::io::SerializableSectionPairParameter parameter{};

      [[nodiscard]] ls::std::core::type::byte_field _getCurrentRow(size_t _iterations, const ls::std::core::type::byte_field &_serializedDocument);
      [[nodiscard]] ls::std::core::type::byte_field _getNextSerializedSection(const ls::std::core::type::byte_field &_serializedDocument);
      [[nodiscard]] bool _isNotNewSection(const ls::std::core::type::byte_field &_currentRow);
      void _addSection(const ls::std::core::type::byte_field &_serializedSection);
  };
}

#endif
