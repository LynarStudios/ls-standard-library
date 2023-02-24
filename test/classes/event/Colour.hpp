/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2022-05-14
 * Changed:         2023-02-23
 *
 * */

#ifndef LS_STD_COLOUR_HPP
#define LS_STD_COLOUR_HPP

#include <ls-std/ls-std-core.hpp>

namespace test::event
{
  class Colour : public ls::std::core::Class
  {
    public:

      explicit Colour(const ::std::string &_value);
      ~Colour() noexcept override;

      [[nodiscard]] ::std::string getValue() const;

    private:

      ::std::string value{};
  };
}

#endif
