/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-16
*
* */

#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>

ls::std::io::SectionPairDocument::SectionPairDocument() : ls::std::core::Class("SectionPairDocument")
{}

ls::std::io::SectionPairDocument::~SectionPairDocument() = default;

void ls::std::io::SectionPairDocument::add(const section_pair_document_section_list_element &_section)
{
  ::std::string message = this->getClassName() + ": add section attempt failed, since \"_section\" argument is null!";
  ls::std::core::NullPointerArgumentEvaluator(::std::reinterpret_pointer_cast<void>(_section), message).evaluate();
  this->_checkSectionExistence(_section->getSectionId());
  this->sections.push_back(_section);
}

ls::std::io::section_pair_document_section_list_element ls::std::io::SectionPairDocument::get(size_t _index)
{
  ls::std::io::section_pair_document_section_list_element element{};
  ls::std::core::IndexOutOfBoundsEvaluator{_index, this->sections.size()}.evaluate();
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

size_t ls::std::io::SectionPairDocument::getAmountOfSections()
{
  return this->sections.size();
}

::std::string ls::std::io::SectionPairDocument::getHeader()
{
  return this->header;
}

ls::std::io::section_pair_document_section_list ls::std::io::SectionPairDocument::getSectionList()
{
  return this->sections;
}

void ls::std::io::SectionPairDocument::_checkSectionExistence(const ls::std::io::section_pair_identifier &_sectionId)
{
  if (this->_hasSection(_sectionId))
  {
    throw ls::std::core::IllegalArgumentException{this->getClassName() + "section ID \"" + _sectionId + "\" already exists in document!"};
  }
}

bool ls::std::io::SectionPairDocument::_hasSection(const ls::std::io::section_pair_identifier &_identifier)
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
