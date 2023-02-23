/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-23
*
* */

#include "SectionPairDocumentProvider.hpp"
#include <classes/io/section-pair/SectionPairSectionProvider.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::type::byte_field;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairSection;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::SectionPairDocumentProvider;
using test::io::SectionPairSectionProvider;

SectionPairDocumentProvider::SectionPairDocumentProvider() = default;

SectionPairDocumentProvider::~SectionPairDocumentProvider() = default;

shared_ptr<SectionPairDocument> SectionPairDocumentProvider::createDocument()
{
  shared_ptr<SectionPairDocument> document = make_shared<SectionPairDocument>();

  // general section

  shared_ptr<SectionPairSection> generalSection = SectionPairSectionProvider::createSectionWithSandraExample();
  document->add(generalSection);

  // physical

  shared_ptr<SectionPairSection> physicalSection = make_shared<SectionPairSection>("physical");

  shared_ptr<SectionPairRow> eyeColor = make_shared<SectionPairRow>("eye-color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(eyeColor->getValue())->set("blue");
  physicalSection->add(eyeColor);

  shared_ptr<SectionPairRow> hairColor = make_shared<SectionPairRow>("hair-color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(hairColor->getValue())->set("red");
  physicalSection->add(hairColor);

  shared_ptr<SectionPairRow> height = make_shared<SectionPairRow>("height", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(height->getValue())->set("167");
  physicalSection->add(height);

  document->add(physicalSection);

  return document;
}

byte_field SectionPairDocumentProvider::createSerializedDocument(const string &_newLine)
{
  byte_field serializedDocument = "# section-pair document" + _newLine;

  // general section

  serializedDocument += SectionPairSectionProvider::createSerializedSectionWithSandraExample(_newLine);

  // physical

  serializedDocument += _newLine + "[physical]" + _newLine + _newLine;
  serializedDocument += "eye-color=blue" + _newLine;
  serializedDocument += "hair-color=red" + _newLine;
  serializedDocument += "height=167" + _newLine;

  return serializedDocument;
}

byte_field SectionPairDocumentProvider::createSerializedDocumentComputerExample(const string &_newLine)
{
  byte_field serializedDocument = "# section-pair document" + _newLine;
  serializedDocument += _newLine + "[model]" + _newLine + _newLine;
  serializedDocument += "graphics-card=GTX 720" + _newLine;
  serializedDocument += "ram-size=4096" + _newLine;
  serializedDocument += "graphics-ram-size=4096" + _newLine;
  serializedDocument += "cpu=Intel i7" + _newLine;

  serializedDocument += _newLine + "[requirements]" + _newLine + _newLine;
  serializedDocument += "graphics-ram-size=2048" + _newLine;
  serializedDocument += "io-devices:" + _newLine;
  serializedDocument += "  mouse" + _newLine;
  serializedDocument += "  keyboard" + _newLine;
  serializedDocument += "  screen" + _newLine;
  serializedDocument += "  headset" + _newLine;

  return serializedDocument;
}
