/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-14
 *
 * */

#ifndef LS_STD_NEWS_AGENCY_HPP
#define LS_STD_NEWS_AGENCY_HPP

#include <string>

namespace ls_std_event_test
{
  class NewsAgency
  {
    public:

      explicit NewsAgency(std::string _agencyName); // TODO: use ::std:: instead of std:: library wide
      ~NewsAgency() = default;

      std::string getName();

    private:

      std::string agencyName{};
  };
}

#endif
