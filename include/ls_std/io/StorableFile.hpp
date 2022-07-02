/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_STORABLE_FILE_HPP
#define LS_STD_STORABLE_FILE_HPP

#include <string>
#include <memory>
#include <ls_std/core/interface/IStorable.hpp>
#include "File.hpp"
#include <ls_std/os/dynamic_goal.hpp>

namespace ls::std::io
{
  class DYNAMIC_GOAL StorableFile : public ls::std::core::interface_type::IStorable
  {
    public:

      explicit StorableFile(const ::std::string &_path);
      ~StorableFile() = default;

      ::std::shared_ptr<ls::std::io::File> getFile();
      ls::std::core::type::byte_field load() override;
      void reset(const ::std::string &_path);
      void save(const ls::std::core::type::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::std::io::File> file{};

      void _init(const ::std::string &_path);
  };
}

#endif
