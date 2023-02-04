/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-03
 *
 * */

#ifndef LS_STD_COLOUR_HPP
#define LS_STD_COLOUR_HPP

#include <ls-std/ls-std-core.hpp>

namespace ls_std_event_test
{
  class Colour : public ls::std::core::Class
  {
    public:

      explicit Colour(const ::std::string &_value);
      ~Colour() override = default;

      [[nodiscard]] ::std::string getValue() const;

    private:

      ::std::string value{};
  };
}

#endif
