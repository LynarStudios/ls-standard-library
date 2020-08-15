/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-15
 *
 * */

#ifndef FILE_HPP
#define FILE_HPP

#include "../base/Class.hpp"
#include <string>

namespace ls_std {
  class File : public Class {
    public:

      explicit File(std::string _absoluteFilePath);
      ~File() = default;

      // comparison operators

      bool operator==(File& _file);
      bool operator!=(File& _file);

      // additional functionality

      bool canExecute();
      void create();
      bool exists();
      std::string getAbsoluteFilePath();
      std::string getName();
      long getSize();
      bool isDirectory();
      bool isFile();
      void makeDirectory();
      void remove();

    private:

      std::string absoluteFilePath {};

      bool _exists();
      bool _isDirectory();
      bool _isFile();
      int _mkdir();
      static std::string _normalizePath(std::string path);
  };
}

#endif
