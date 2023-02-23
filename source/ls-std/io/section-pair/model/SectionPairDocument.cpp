/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-23
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairDocument.hpp>

using ls::std::core::Class;
using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::IllegalArgumentException;
using ls::std::core::IndexOutOfBoundsEvaluator;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::section_pair_document_section_list;
using ls::std::io::section_pair_document_section_list_element;
using ls::std::io::section_pair_identifier;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SerializableSectionPairDocument;
using ls::std::io::SerializableSectionPairParameter;
using std::make_shared;
using std::reinterpret_pointer_cast;
using std::string;

SectionPairDocument::SectionPairDocument() : Class("SectionPairDocument")
{}

SectionPairDocument::~SectionPairDocument() noexcept = default;

void SectionPairDocument::add(const section_pair_document_section_list_element &_section)
{
  string message = this->getClassName() + ": add section attempt failed, since \"_section\" argument is null!";
  NullPointerArgumentEvaluator(reinterpret_pointer_cast<void>(_section), message).evaluate();
  this->_checkSectionExistence(_section->getSectionId());
  this->sections.push_back(_section);
}

void SectionPairDocument::clear()
{
  this->sections.clear();
}

section_pair_document_section_list_element SectionPairDocument::get(size_t _index)
{
  section_pair_document_section_list_element element{};
  IndexOutOfBoundsEvaluator{_index, this->sections.size()}.evaluate();
  size_t index{};

  for (const auto &_element : this->sections)
  {
    if (_index == index)
    {
      element = _element;
      break;
    }

    ++index;
  }

  return element;
}

section_pair_document_section_list_element SectionPairDocument::get(const section_pair_identifier &_sectionId)
{
  return this->_get(_sectionId);
}

size_t SectionPairDocument::getAmountOfSections()
{
  return this->sections.size();
}

string SectionPairDocument::getHeader()
{
  return this->header;
}

section_pair_document_section_list SectionPairDocument::getSectionList()
{
  return this->sections;
}

bool SectionPairDocument::hasSection(const section_pair_identifier &_sectionId)
{
  return this->_hasSection(_sectionId);
}

byte_field SectionPairDocument::marshal()
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void SectionPairDocument::reserveNewLine(const string &_reservedNewLine)
{
  this->reservedNewLine = _reservedNewLine;
}

void SectionPairDocument::unmarshal(const byte_field &_data)
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void SectionPairDocument::_checkSectionExistence(const section_pair_identifier &_sectionId)
{
  if (this->_hasSection(_sectionId))
  {
    string message = this->getClassName() + "section ID \"" + _sectionId + "\" already exists in document!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}

void SectionPairDocument::_createSerializable()
{
  SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = make_shared<SerializableSectionPairDocument>(parameter);
}

section_pair_document_section_list_element SectionPairDocument::_get(const section_pair_identifier &_sectionId)
{
  section_pair_document_section_list_element element{};

  for (const auto &_section : this->sections)
  {
    if (_section->getSectionId() == _sectionId)
    {
      element = _section;
      break;
    }
  }

  return element;
}

bool SectionPairDocument::_hasSection(const section_pair_identifier &_identifier)
{
  bool sectionExists{};

  for (const auto &_section : this->sections)
  {
    if (_section->getSectionId() == _identifier)
    {
      sectionExists = true;
      break;
    }
  }

  return sectionExists;
}
