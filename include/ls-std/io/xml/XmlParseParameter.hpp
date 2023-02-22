/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-10-17
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_XML_PARSE_PARAMETER_HPP
#define LS_STD_XML_PARSE_PARAMETER_HPP

#include "XmlNode.hpp"
#include <cstdint>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlParseParameter
  {
    public:

      XmlParseParameter();
      ~XmlParseParameter();

      [[nodiscard]] uint8_t getLevel() const;
      [[nodiscard]] ::std::shared_ptr<ls::std::io::XmlNode> getNode();
      void setLevel(const uint8_t &_level);
      void setNode(const ::std::shared_ptr<ls::std::io::XmlNode> &_node);

    private:

      uint8_t level{};
      ::std::shared_ptr<ls::std::io::XmlNode> node{};

      void _setNode(const ::std::shared_ptr<ls::std::io::XmlNode> &_node);
  };
}

#endif
