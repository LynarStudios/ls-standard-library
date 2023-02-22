/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-21
*
* */

#include "SectionPairDocumentProvider.hpp"
#include <classes/io/section-pair/SectionPairSectionProvider.hpp>
#include <ls-std/ls-std-io.hpp>

test::io::SectionPairDocumentProvider::SectionPairDocumentProvider() = default;

test::io::SectionPairDocumentProvider::~SectionPairDocumentProvider() = default;

::std::shared_ptr<ls::std::io::SectionPairDocument> test::io::SectionPairDocumentProvider::createDocument()
{
  ::std::shared_ptr<ls::std::io::SectionPairDocument> document = ::std::make_shared<ls::std::io::SectionPairDocument>();

  // general section

  ::std::shared_ptr<ls::std::io::SectionPairSection> generalSection = test::io::SectionPairSectionProvider::createSectionWithSandraExample();
  document->add(generalSection);

  // physical

  ::std::shared_ptr<ls::std::io::SectionPairSection> physicalSection = ::std::make_shared<ls::std::io::SectionPairSection>("physical");

  ::std::shared_ptr<ls::std::io::SectionPairRow> eyeColor = ::std::make_shared<ls::std::io::SectionPairRow>("eye-color", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(eyeColor->getValue())->set("blue");
  physicalSection->add(eyeColor);

  ::std::shared_ptr<ls::std::io::SectionPairRow> hairColor = ::std::make_shared<ls::std::io::SectionPairRow>("hair-color", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(hairColor->getValue())->set("red");
  physicalSection->add(hairColor);

  ::std::shared_ptr<ls::std::io::SectionPairRow> height = ::std::make_shared<ls::std::io::SectionPairRow>("height", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(height->getValue())->set("167");
  physicalSection->add(height);

  document->add(physicalSection);

  return document;
}

ls::std::core::type::byte_field test::io::SectionPairDocumentProvider::createSerializedDocument(const ::std::string &_newLine)
{
  ls::std::core::type::byte_field serializedDocument = "# section-pair document" + _newLine;

  // general section

  serializedDocument += test::io::SectionPairSectionProvider::createSerializedSectionWithSandraExample(_newLine);

  // physical

  serializedDocument += _newLine + "[physical]" + _newLine + _newLine;
  serializedDocument += "eye-color=blue" + _newLine;
  serializedDocument += "hair-color=red" + _newLine;
  serializedDocument += "height=167" + _newLine;

  return serializedDocument;
}

ls::std::core::type::byte_field test::io::SectionPairDocumentProvider::createSerializedDocumentComputerExample(const ::std::string &_newLine)
{
  ls::std::core::type::byte_field serializedDocument = "# section-pair document" + _newLine;
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
