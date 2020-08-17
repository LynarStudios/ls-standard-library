/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-17
 *
 * */

#ifndef FILE_HPP
#define FILE_HPP

#include "../base/Class.hpp"
#include <string>
#include <vector>
#include <list>
#include <ctime>

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
      void createNewFile();
      bool exists();
      std::string getAbsoluteFilePath();
      std::string getName();
      std::string getParent();
      long getSize();
      bool isDirectory();
      bool isFile();
      time_t lastModified();
      std::list<std::string> list();
      std::list<std::string> listFiles();
      void makeDirectory();
      void makeDirectories();
      void remove();

    private:

      std::string absoluteFilePath {};

      static bool _exists(const std::string& _path);
      static std::string _getParent(const std::string& _path);
      static bool _isDirectory(const std::string& _path);
      static bool _isFile(const std::string& _path);
      static time_t _lastModified(const std::string& _path);
      static std::list<std::string> _list(const std::string& _path);
      static std::list<std::string> _listFiles(const std::string& _path);
      #if defined(unix) || defined(__APPLE__)
        static std::list<std::string> _listUnix(const std::string& _path, bool withDirectories);
      #endif
      #ifdef _WIN32
        static std::list<std::string> _listWindows(const std::string& _path, bool withDirectories);
      #endif
      static int _mkdir(const std::string& _path);
      static std::string _normalizePath(std::string _path);
      static std::vector<std::string> _splitIntoSubDirectoryNames(const std::string& _path);
  };
}

#endif
