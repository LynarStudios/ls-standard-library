/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2022-05-14
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_event.hpp>
#include <ls_std_event_test.hpp>

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
    ls::std::event::EventManager eventManager{};
    ASSERT_STREQ("EventManager", eventManager.getClassName().c_str());
  }

  TEST_F(EventManagerTest, subscribe_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.subscribe("", std::make_shared<ls_std_event_test::DailyNewsAgency>());
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, subscribe_no_listener)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.subscribe("TMP_ID", nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, subscribe_no_event_handler_available)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.subscribe("TMP_DIR", std::make_shared<ls_std_event_test::DailyNewsAgency>());
                   }
                   catch (const ls::std::core::EventNotSubscribedException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::EventNotSubscribedException);
  }

  TEST_F(EventManagerTest, unsubscribe_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.unsubscribe("", std::make_shared<ls_std_event_test::DailyNewsAgency>());
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, unsubscribe_no_listener)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.unsubscribe("TMP_ID", nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, addEventHandler)
  {
    ls::std::event::EventManager eventManager{};
    ASSERT_TRUE(eventManager.addEventHandler(std::make_shared<ls::std::event::EventHandler>("TMP_ID")));
  }

  TEST_F(EventManagerTest, addEventHandler_event_handler_already_exists)
  {
    ls::std::event::EventManager eventManager{};
    ASSERT_TRUE(eventManager.addEventHandler(std::make_shared<ls::std::event::EventHandler>("TMP_ID")));
    ASSERT_FALSE(eventManager.addEventHandler(std::make_shared<ls::std::event::EventHandler>("TMP_ID")));
  }

  TEST_F(EventManagerTest, addEventHandler_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.addEventHandler(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, fire_event_handler_not_available)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.fire(ls::std::event::Event{"TMP_ID"});
                   }
                   catch (const ls::std::core::EventNotHandledException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::EventNotHandledException);
  }

  TEST_F(EventManagerTest, hasEventHandler)
  {
    ls::std::event::EventManager eventManager{};
    eventManager.addEventHandler(std::make_shared<ls::std::event::EventHandler>("TMP_ID"));
    ASSERT_TRUE(eventManager.hasEventHandler("TMP_ID"));
  }

  TEST_F(EventManagerTest, hasEventHandler_no_event_handler_available)
  {
    ls::std::event::EventManager eventManager{};
    ASSERT_FALSE(eventManager.hasEventHandler("TMP_ID"));
  }

  TEST_F(EventManagerTest, hasEventHandler_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.hasEventHandler("");
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, removeEventHandler)
  {
    ls::std::event::EventManager eventManager{};
    std::shared_ptr<ls::std::event::EventHandler> eventHandler = std::make_shared<ls::std::event::EventHandler>("TMP_ID");
    eventManager.addEventHandler(eventHandler);

    ASSERT_TRUE(eventManager.removeEventHandler(eventHandler));
  }

  TEST_F(EventManagerTest, removeEventHandler_no_event_handler_available)
  {
    ls::std::event::EventManager eventManager{};
    ASSERT_FALSE(eventManager.removeEventHandler(std::make_shared<ls::std::event::EventHandler>("TMP_ID")));
  }

  TEST_F(EventManagerTest, removeEventHandler_no_reference)
  {
    EXPECT_THROW({
                   try
                   {
                     ls::std::event::EventManager eventManager{};
                     eventManager.removeEventHandler(nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, production_example)
  {
    std::string news, expectedNews{};
    ls::std::core::type::event_id seriousNewsEventId = ls_std_event_test::SeriousNewsEvent{""}.getId();
    ls::std::core::type::event_id gossipNewsEventId = ls_std_event_test::GossipNewsEvent{""}.getId();

    // create event handler

    std::shared_ptr<ls::std::event::EventHandler> seriousNewsEventHandler = std::make_shared<ls::std::event::EventHandler>(seriousNewsEventId);   // event id
    std::shared_ptr<ls::std::event::EventHandler> gossipNewsEventHandler = std::make_shared<ls::std::event::EventHandler>(gossipNewsEventId);     // event id

    // create and fill event manager with handler

    std::shared_ptr<ls::std::event::EventManager> eventManager = std::make_shared<ls::std::event::EventManager>();
    eventManager->addEventHandler(seriousNewsEventHandler);
    eventManager->addEventHandler(gossipNewsEventHandler);

    // create news agency (listener)

    std::shared_ptr<ls_std_event_test::DailyNewsAgency> dailyNews = std::make_shared<ls_std_event_test::DailyNewsAgency>();
    std::shared_ptr<ls_std_event_test::GossipNewsAgency> gossipNews = std::make_shared<ls_std_event_test::GossipNewsAgency>();

    // fire SeriousNewsEvent event with no effect

    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call
    ASSERT_TRUE(dailyNews->getNews().empty());
    ASSERT_TRUE(gossipNews->getNews().empty());

    // now subscribe to SeriousNewsEvent and fire SeriousNewsEvent event

    eventManager->subscribe(seriousNewsEventId, dailyNews);
    eventManager->subscribe(seriousNewsEventId, gossipNews);
    news = "COVID-19 is still going on!";
    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    dailyNews->clear();
    gossipNews->clear();

    // unsubscribe SeriousNewsEvent from GossipNewsAgency

    eventManager->unsubscribe(seriousNewsEventId, gossipNews);
    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call

    expectedNews = "DailyNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
    ASSERT_TRUE(gossipNews->getNews().empty());

    dailyNews->clear();
    gossipNews->clear();

    // now let GossipNewsAgency subscribe to SeriousNewsEvent + GossipNewsEvent and fire both of them

    eventManager->subscribe(gossipNewsEventId, gossipNews);
    eventManager->subscribe(seriousNewsEventId, gossipNews);

    news = "COVID-19 is still going on!";
    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());

    news = "ape likes banana!";
    eventManager->fire(ls_std_event_test::GossipNewsEvent(news)); // event call
    expectedNews = "GossipNewsAgency: " + news;
    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
  }
}
