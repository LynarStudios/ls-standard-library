/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_NEWS_AGENCY_HPP
#define LS_STD_NEWS_AGENCY_HPP

#include <string>

namespace test::event
{
  class NewsAgency
  {
    public:

      explicit NewsAgency(::std::string _agencyName);
      virtual ~NewsAgency();

      ::std::string getName();

    private:

      ::std::string agencyName{};
  };
}

#endif
