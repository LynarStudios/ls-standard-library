/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2020-08-19
 *
 * */

#ifndef FILE_HPP
#define FILE_HPP

#include "../base/Class.hpp"
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <regex>

#if defined(unix) || defined(__APPLE__)
#include <dirent.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

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
      bool canRead();
      bool canWrite();
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
      bool renameTo(const std::string& _newName);

    private:

      std::string absoluteFilePath {};

      #if defined(unix) || defined(__APPLE__)
        static void _addToFileListUnix(const std::string& _path, bool _withDirectories, dirent* directoryEntity, std::list<std::string>& _list);
      #endif
      #ifdef _WIN32
        static void _addToFileListWindows(const std::string& _path, bool _withDirectories, WIN32_FIND_DATA _data, std::list<std::string>& _list);
      #endif
      static bool _exists(const std::string& _path);
      static std::string _getParent(const std::string& _path);
      static bool _isDirectory(const std::string& _path);
      static bool _isExecutable(const std::string& _path);
      static bool _isFile(const std::string& _path);
      #if defined(unix) || defined(__APPLE__)
        static bool _isReadableUnix(const std::string& _path);
      #endif
      #ifdef _WIN32
        static bool _isReadableWindows(const std::string& _path);
      #endif
      static bool _isWritable(const std::string& _path);
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
      static std::string _reduceSeparators(const std::string& _path);
      static bool _renameTo(const std::string& _oldName, const std::string& _newName);
      static std::string _replaceWrongSeparator(std::string _path);
      static std::vector<std::string> _splitIntoSubDirectoryNames(const std::string& _path);
  };
}

#endif
