/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-02-03
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-event.hpp>
#include <ls-std-event-test.hpp>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::event;
using namespace ::std;
using namespace ls_std_event_test;

namespace
{
  class EventManagerTest : public ::testing::Test
  {
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
    EventManager eventManager{};
    ASSERT_STREQ("EventManager", eventManager.getClassName().c_str());
  }

  TEST_F(EventManagerTest, subscribe_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.subscribe("", make_shared<DailyNewsAgency>());
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, subscribe_no_listener)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.subscribe("TMP_ID", nullptr);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, subscribe_no_event_handler_available)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.subscribe("TMP_DIR", make_shared<DailyNewsAgency>());
                   }
                   catch (const EventNotSubscribedException &_exception)
                   {
                     throw;
                   }
                 }, EventNotSubscribedException);
  }

  TEST_F(EventManagerTest, unsubscribe_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.unsubscribe("", make_shared<DailyNewsAgency>());
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, unsubscribe_no_listener)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.unsubscribe("TMP_ID", nullptr);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, addEventHandler)
  {
    EventManager eventManager{};
    ASSERT_TRUE(eventManager.addEventHandler(make_shared<EventHandler>("TMP_ID")));
  }

  TEST_F(EventManagerTest, addEventHandler_event_handler_already_exists)
  {
    EventManager eventManager{};
    ASSERT_TRUE(eventManager.addEventHandler(make_shared<EventHandler>("TMP_ID")));
    ASSERT_FALSE(eventManager.addEventHandler(make_shared<EventHandler>("TMP_ID")));
  }

  TEST_F(EventManagerTest, addEventHandler_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.addEventHandler(nullptr);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, fire_event_handler_not_available)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.fire(Event{"TMP_ID"});
                   }
                   catch (const EventNotHandledException &_exception)
                   {
                     throw;
                   }
                 }, EventNotHandledException);
  }

  TEST_F(EventManagerTest, hasEventHandler)
  {
    EventManager eventManager{};
    eventManager.addEventHandler(make_shared<EventHandler>("TMP_ID"));
    ASSERT_TRUE(eventManager.hasEventHandler("TMP_ID"));
  }

  TEST_F(EventManagerTest, hasEventHandler_no_event_handler_available)
  {
    EventManager eventManager{};
    ASSERT_FALSE(eventManager.hasEventHandler("TMP_ID"));
  }

  TEST_F(EventManagerTest, hasEventHandler_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.hasEventHandler("");
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, removeEventHandler)
  {
    EventManager eventManager{};
    shared_ptr<EventHandler> eventHandler = make_shared<EventHandler>("TMP_ID");
    eventManager.addEventHandler(eventHandler);

    ASSERT_TRUE(eventManager.removeEventHandler(eventHandler));
  }

  TEST_F(EventManagerTest, removeEventHandler_no_event_handler_available)
  {
    EventManager eventManager{};
    ASSERT_FALSE(eventManager.removeEventHandler(make_shared<EventHandler>("TMP_ID")));
  }

  TEST_F(EventManagerTest, removeEventHandler_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     eventManager.removeEventHandler(nullptr);
                   }
                   catch (const IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, IllegalArgumentException);
  }

  TEST_F(EventManagerTest, production_example)
  {
    string news, expectedNews{};
    event_id seriousNewsEventId = SeriousNewsEvent{""}.getId();
    event_id gossipNewsEventId = GossipNewsEvent{""}.getId();

    // create event handler

    shared_ptr<EventHandler> seriousNewsEventHandler = make_shared<EventHandler>(seriousNewsEventId);   // event id
    shared_ptr<EventHandler> gossipNewsEventHandler = make_shared<EventHandler>(gossipNewsEventId);     // event id

    // create and fill event manager with handler

    shared_ptr<EventManager> eventManager = make_shared<EventManager>();
    eventManager->addEventHandler(seriousNewsEventHandler);
    eventManager->addEventHandler(gossipNewsEventHandler);

    // create news agency (listener)

    shared_ptr<DailyNewsAgency> dailyNews = make_shared<DailyNewsAgency>();
    shared_ptr<GossipNewsAgency> gossipNews = make_shared<GossipNewsAgency>();

    // fire SeriousNewsEvent event with no effect

    eventManager->fire(SeriousNewsEvent(news)); // event call
    ASSERT_TRUE(dailyNews->getNews().empty());
    ASSERT_TRUE(gossipNews->getNews().empty());

    // now subscribe to SeriousNewsEvent and fire SeriousNewsEvent event

    eventManager->subscribe(seriousNewsEventId, dailyNews);
    eventManager->subscribe(seriousNewsEventId, gossipNews);
    news = "COVID-19 is still going on!";
    eventManager->fire(SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    dailyNews->clear();
    gossipNews->clear();

    // unsubscribe SeriousNewsEvent from GossipNewsAgency

    eventManager->unsubscribe(seriousNewsEventId, gossipNews);
    eventManager->fire(SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    ASSERT_TRUE(gossipNews->getNews().empty());

    dailyNews->clear();
    gossipNews->clear();

    // now let GossipNewsAgency subscribe to SeriousNewsEvent + GossipNewsEvent and fire both of them

    eventManager->subscribe(gossipNewsEventId, gossipNews);
    eventManager->subscribe(seriousNewsEventId, gossipNews);

    news = "COVID-19 is still going on!";
    eventManager->fire(SeriousNewsEvent(news)); // event call
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    news = "ape likes banana!";
    eventManager->fire(GossipNewsEvent(news)); // event call
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
  }
}
