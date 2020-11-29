/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-29
 *
 * */

#ifndef LS_STD_DAILY_NEWS_AGENCY_HPP
#define LS_STD_DAILY_NEWS_AGENCY_HPP

#include <string>
#include <memory>
#include <map>
#include <ls_std/ls_std.hpp>
#include "NewsAgency.hpp"

namespace ls_std_test {
  class DailyNewsAgency : public ls_std_test::NewsAgency, public ls_std::IListener {
    public:

      DailyNewsAgency();
      ~DailyNewsAgency() override = default;

      // implementation

      void listen(const ls_std::Class& _info) override;

      // additional functionality

      void clear();
      std::string getNews();

    private:

      std::string news {};
  };
}

#endif
