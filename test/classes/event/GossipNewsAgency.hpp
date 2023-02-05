/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-05
 *
 * */

#ifndef LS_STD_GOSSIP_NEWS_AGENCY_HPP
#define LS_STD_GOSSIP_NEWS_AGENCY_HPP

#include "NewsAgency.hpp"
#include <ls-std/ls-std-core.hpp>
#include <map>
#include <memory>
#include <string>

namespace test::event
{
  class GossipNewsAgency : public test::event::NewsAgency, public ls::std::core::interface_type::IListener
  {
    public:

      GossipNewsAgency();
      ~GossipNewsAgency() override;

      // implementation

      void listen(const ls::std::core::Class &_info) override;

      // additional functionality

      void clear();
      ::std::string getNews();

    private:

      ::std::string news{};
  };
}

#endif
