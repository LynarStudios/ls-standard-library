/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-09-23
 * Changed:         2022-10-23
 *
 * */

#ifndef LS_STD_XML_ATTRIBUTE_HPP
#define LS_STD_XML_ATTRIBUTE_HPP

#include <ls_std/core/Class.hpp>
#include <string>
#include <ls_std/os/library/goals/dynamic_goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL XmlAttribute : public ls::std::core::Class
  {
    public:

      explicit XmlAttribute(const ::std::string &_name);
      ~XmlAttribute() override = default;

      ::std::string getName();
      ::std::string getValue();
      void setName(const ::std::string &_name);
      void setValue(const ::std::string &_value);
      ::std::string toXml();

    private:

      ::std::string name{};
      ::std::string value{};

      void _assignName(const ::std::string &_name);
      void _assignValue(const ::std::string &_value);
  };
}

#endif
