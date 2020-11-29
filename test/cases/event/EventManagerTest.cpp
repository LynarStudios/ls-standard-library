/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2020-11-29
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std.hpp>
#include <ls_std_test.hpp>

namespace {
  class EventManagerTest : public ::testing::Test {
    protected:

      EventManagerTest() = default;
      ~EventManagerTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(EventManagerTest, getClassName)
  {
    ls_std::EventManager eventManager {};
    ASSERT_STREQ("EventManager", eventManager.getClassName().c_str());
  }

  TEST_F(EventManagerTest, production_example)
  {
    std::string news, expectedNews {};
    ls_std::event_id seriousNewsEventId = ls_std_test::SeriousNewsEvent {""}.getId();
    ls_std::event_id gossipNewsEventId = ls_std_test::GossipNewsEvent {""}.getId();

    // create event handler

    std::shared_ptr<ls_std::EventHandler> seriousNewsEventHandler = std::make_shared<ls_std::EventHandler>(seriousNewsEventId);   // event id
    std::shared_ptr<ls_std::EventHandler> gossipNewsEventHandler = std::make_shared<ls_std::EventHandler>(gossipNewsEventId);     // event id

    // create and fill event manager with handler

    std::shared_ptr<ls_std::EventManager> eventManager = std::make_shared<ls_std::EventManager>();
    eventManager->addEventHandler(seriousNewsEventHandler);
    eventManager->addEventHandler(gossipNewsEventHandler);

    // create news agency (listener)

    std::shared_ptr<ls_std_test::DailyNewsAgency> dailyNews = std::make_shared<ls_std_test::DailyNewsAgency>();
    std::shared_ptr<ls_std_test::GossipNewsAgency> gossipNews = std::make_shared<ls_std_test::GossipNewsAgency>();

    // fire SeriousNewsEvent event with no effect

    eventManager->fire(ls_std_test::SeriousNewsEvent(news)); // event call
    ASSERT_TRUE(dailyNews->getNews().empty());
    ASSERT_TRUE(gossipNews->getNews().empty());

    // now subscribe to SeriousNewsEvent and fire SeriousNewsEvent event

    eventManager->subscribe(seriousNewsEventId, dailyNews);
    eventManager->subscribe(seriousNewsEventId, gossipNews);
    news = "COVID-19 is still going on!";
    eventManager->fire(ls_std_test::SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    dailyNews->clear();
    gossipNews->clear();

    // unsubscribe SeriousNewsEvent from GossipNewsAgency

    eventManager->unsubscribe(seriousNewsEventId, gossipNews);
    eventManager->fire(ls_std_test::SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    ASSERT_TRUE(gossipNews->getNews().empty());

    dailyNews->clear();
    gossipNews->clear();

    // now let GossipNewsAgency subscribe to SeriousNewsEvent + GossipNewsEvent and fire both of them

    eventManager->subscribe(gossipNewsEventId, gossipNews);
    eventManager->subscribe(seriousNewsEventId, gossipNews);

    news = "COVID-19 is still going on!";
    eventManager->fire(ls_std_test::SeriousNewsEvent(news)); // event call
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    news = "ape likes banana!";
    eventManager->fire(ls_std_test::GossipNewsEvent(news)); // event call
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
  }
}
