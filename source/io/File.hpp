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
#include <vector>

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
      void makeDirectories();
      void remove();

    private:

      std::string absoluteFilePath {};

      bool _exists(const std::string& path);
      bool _isDirectory(const std::string& path);
      bool _isFile(const std::string& path);
      static int _mkdir(const std::string& path);
      static std::string _normalizePath(std::string path);
      static std::vector<std::string> _splitIntoSubDirectoryNames(const std::string& path);
  };
}

#endif
