/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2022-05-12
 *
 * */

#ifndef LS_STD_STORABLE_FILE_HPP
#define LS_STD_STORABLE_FILE_HPP

#include <string>
#include <memory>
#include <ls_std/core/interface/IStorable.hpp>
#include "File.hpp"

namespace ls
{
  namespace std
  {
    namespace io
    {
      class StorableFile : public ls::std::core::IStorable
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
  }
}

#endif
