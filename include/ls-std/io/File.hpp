/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_FILE_HPP
#define LS_STD_FILE_HPP

#include <ctime>
#if defined(unix) || defined(__APPLE__)
  #include <dirent.h>
#endif
#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <regex>
#include <string>
#include <vector>
#ifdef _WIN32
  #include <windows.h>
#endif

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL File : public ls::std::core::Class
  {
    public:

      explicit File(::std::string _absoluteFilePath);
      ~File() override;

      // comparison operators

      bool operator==(ls::std::io::File &_file);
      bool operator!=(ls::std::io::File &_file);

      // additional functionality

      [[nodiscard]] bool canExecute();
      [[nodiscard]] bool canRead();
      [[nodiscard]] bool canWrite();
      void createNewFile();
      [[nodiscard]] bool exists();
      [[nodiscard]] ::std::string getAbsoluteFilePath();
      [[nodiscard]] ::std::string getName();
      [[nodiscard]] ::std::string getParent();
      [[nodiscard]] long getSize();
      [[nodiscard]] static ::std::string getWorkingDirectory();
      [[nodiscard]] bool isDirectory();
      [[nodiscard]] bool isFile();
      [[nodiscard]] time_t lastModified();
      [[nodiscard]] ::std::list<::std::string> list();
      [[nodiscard]] ::std::list<::std::string> listFiles();
      void makeDirectory();
      void makeDirectories();
      void remove();
      bool renameTo(const ::std::string &_newName); // nodiscard is optional here
      void reset(const ::std::string &_newPath);

    private:

      ::std::string absoluteFilePath{};

#if defined(unix) || defined(__APPLE__)
      static void _addToFileListUnix(const ::std::string &_path, bool _withDirectories, dirent *directoryEntity, ::std::list<::std::string> &_list);
#endif
#ifdef _WIN32
      static void _addToFileListWindows(const ::std::string &_path, bool _withDirectories, WIN32_FIND_DATA _data, ::std::list<::std::string> &_list);
#endif
      [[nodiscard]] static bool _equals(ls::std::io::File &_file, ls::std::io::File &_foreignFile);
      [[nodiscard]] static bool _exists(const ::std::string &_path);
      [[nodiscard]] static ::std::string _getParent(const ::std::string &_path);
#if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static ::std::string _getWorkingDirectoryUnix();
#endif
#ifdef _WIN32
      [[nodiscard]] static ::std::string _getWorkingDirectoryWindows();
#endif
      [[nodiscard]] static bool _isDirectory(const ::std::string &_path);
      [[nodiscard]] static bool _isExecutable(const ::std::string &_path);
      [[nodiscard]] static bool _isFile(const ::std::string &_path);
#if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static bool _isReadableUnix(const ::std::string &_path);
#endif
#ifdef _WIN32
      [[nodiscard]] static bool _isReadableWindows(const ::std::string &_path);
#endif
      [[nodiscard]] static bool _isWritable(const ::std::string &_path);
      [[nodiscard]] static time_t _lastModified(const ::std::string &_path);
      [[nodiscard]] static ::std::list<::std::string> _list(const ::std::string &_path);
      [[nodiscard]] static ::std::list<::std::string> _listFiles(const ::std::string &_path);
#if defined(unix) || defined(__APPLE__)
      [[nodiscard]] static ::std::list<::std::string> _listUnix(const ::std::string &_path, bool withDirectories);
#endif
#ifdef _WIN32
      [[nodiscard]] static ::std::list<::std::string> _listWindows(const ::std::string &_path, bool withDirectories);
#endif
      [[nodiscard]] static bool _makeDirectory(const ::std::string &_path);
      [[nodiscard]] static ::std::string _normalizePath(::std::string _path);
      [[nodiscard]] static ::std::string _reduceSeparators(const ::std::string &_path);
      static void _remove(const ::std::string &_path);
#if defined(unix) || defined(__APPLE__)
      static void _removeUnix(const ::std::string &_path);
#endif
#ifdef _WIN32
      static void _removeWindows(const ::std::string &_path);
#endif
      [[nodiscard]] static bool _renameTo(const ::std::string &_oldName, const ::std::string &_newName);
      [[nodiscard]] static ::std::string _replaceWrongSeparator(::std::string _path);
      [[nodiscard]] static ::std::vector<::std::string> _splitIntoSubDirectoryNames(const ::std::string &_path);
  };
}

#endif
