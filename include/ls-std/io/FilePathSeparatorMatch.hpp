/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-15
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_FILE_PATH_MATCH_HPP
#define LS_STD_FILE_PATH_MATCH_HPP

namespace ls::std::io
{
  class FilePathSeparatorMatch
  {
    public:

      FilePathSeparatorMatch();
      ~FilePathSeparatorMatch();

      bool operator()(char _char) const;
  };
}

#endif
