/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-14
 *
 * */

#ifndef LS_STD_DAILY_NEWS_AGENCY_HPP
#define LS_STD_DAILY_NEWS_AGENCY_HPP

#include <string>
#include <memory>
#include <map>
#include <ls_std/ls_std_core.hpp>
#include "NewsAgency.hpp"

namespace ls_std_test // TODO: change namespace to event specific namespace
{
  class DailyNewsAgency : public ls_std_test::NewsAgency, public ls::std::core::IListener
  {
    public:

      DailyNewsAgency();
      ~DailyNewsAgency() = default;

      // implementation

      void listen(const ls::std::core::Class &_info) override;

      // additional functionality

      void clear();
      std::string getNews();

    private:

      std::string news{};
  };
}

#endif
