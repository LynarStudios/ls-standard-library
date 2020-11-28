/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-28
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <ls_std_test.hpp>

namespace {
  class EventHandlerTest : public ::testing::Test {
    protected:

      EventHandlerTest() = default;
      ~EventHandlerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(EventHandlerTest, getId)
  {
    ls_std::EventHandler eventHandler {"EventId"};
    ASSERT_STREQ("EventId", eventHandler.getId().c_str());
  }

  TEST_F(EventHandlerTest, production_example)
  {
    std::string news, expectedNews {};
    ls_std::event_id seriousNewsEventId = ls_std_test::SeriousNewsEvent {""}.getId();
    ls_std::event_id gossipNewsEventId = ls_std_test::GossipNewsEvent {""}.getId();

    // create event handler

    std::shared_ptr<ls_std::EventHandler> seriousNewsEventHandler = std::make_shared<ls_std::EventHandler>(seriousNewsEventId);   // event id
    std::shared_ptr<ls_std::EventHandler> gossipNewsEventHandler = std::make_shared<ls_std::EventHandler>(gossipNewsEventId);     // event id

    // create news agency (listener)

    std::shared_ptr<ls_std_test::DailyNewsAgency> dailyNews = std::make_shared<ls_std_test::DailyNewsAgency>();
    std::shared_ptr<ls_std_test::GossipNewsAgency> gossipNews = std::make_shared<ls_std_test::GossipNewsAgency>();

    // add handler of those events, every news agency should know
    // this is how agencies know about events

    dailyNews->addEventHandler(seriousNewsEventHandler);

    gossipNews->addEventHandler(seriousNewsEventHandler);
    gossipNews->addEventHandler(gossipNewsEventHandler);

    // fire SeriousNewsEvent event with no effect

    seriousNewsEventHandler->tell(ls_std_test::SeriousNewsEvent(news)); // event call
    ASSERT_TRUE(dailyNews->getNews().empty());
    ASSERT_TRUE(gossipNews->getNews().empty());

    // now subscribe to SeriousNewsEvent and fire SeriousNewsEvent event

    dailyNews->subscribe(seriousNewsEventId);
    gossipNews->subscribe(seriousNewsEventId);
    news = "COVID-19 is still going on!";
    seriousNewsEventHandler->tell(ls_std_test::SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    dailyNews->clear();
    gossipNews->clear();

    // unsubscribe SeriousNewsEvent from GossipNewsAgency

    gossipNews->unsubscribe(seriousNewsEventId);
    seriousNewsEventHandler->tell(ls_std_test::SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    ASSERT_TRUE(gossipNews->getNews().empty());

    dailyNews->clear();
    gossipNews->clear();

    // now let GossipNewsAgency subscribe to SeriousNewsEvent + GossipNewsEvent and fire both of them

    gossipNews->subscribe(gossipNewsEventId);
    gossipNews->subscribe(seriousNewsEventId);

    news = "COVID-19 is still going on!";
    seriousNewsEventHandler->tell(ls_std_test::SeriousNewsEvent(news));
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    news = "ape likes banana!";
    seriousNewsEventHandler->tell(ls_std_test::GossipNewsEvent(news));
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
  }
}
