/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-19
 * Changed:         2020-08-19
 *
 * */

#ifndef STORABLE_FILE_HPP
#define STORABLE_FILE_HPP

#include <string>
#include <memory>
#include "IStorable.hpp"
#include "File.hpp"

namespace ls_std {
  class StorableFile : public IStorable {
    public:

      explicit StorableFile(const std::string& _path);
      ~StorableFile() = default;

      std::string getContent();
      void load() override;
      void reset(const std::string& _path);
      void save() override;
      void setContent(const std::string& _content);

    private:

      std::string content {};
      std::shared_ptr<ls_std::File> file {};

      void _init(const std::string& _path);
  };
}

#endif
