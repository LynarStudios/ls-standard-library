/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_STORABLE_FILE_HPP
#define LS_STD_STORABLE_FILE_HPP

#include "File.hpp"
#include <ls-std/core/interface/IStorable.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <string>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL StorableFile : public ls::std::core::interface_type::IStorable
  {
    public:

      explicit StorableFile(const ::std::string &_path);
      ~StorableFile() noexcept override;

      [[nodiscard]] ::std::shared_ptr<ls::std::io::File> getFile();
      [[nodiscard]] ls::std::core::type::byte_field load() override;
      void reset(const ::std::string &_path);
      void save(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::io::File> file{};

      void _init(const ::std::string &_path);
  };
}

#endif
