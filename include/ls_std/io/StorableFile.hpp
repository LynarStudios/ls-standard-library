/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_STORABLE_FILE_HPP
#define LS_STD_STORABLE_FILE_HPP

#include <string>
#include <memory>
#include "IStorable.hpp"
#include "File.hpp"

namespace ls
{
  class StorableFile : public ls::IStorable
  {
    public:

      explicit StorableFile(const ::std::string &_path);
      ~StorableFile() = default;

      ::std::shared_ptr<ls::File> getFile();
      ls::std::core::byte_field load() override;
      void reset(const ::std::string &_path);
      void save(const ls::std::core::byte_field &_data) override;

    private:

      ::std::shared_ptr<ls::File> file{};

      void _init(const ::std::string &_path);
  };
}

#endif
