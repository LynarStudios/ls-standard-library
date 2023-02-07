/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-27
 * Changed:         2023-01-06
 *
 * */

#include <gtest/gtest.h>
#include <ls_std/ls_std_event.hpp>
#include <ls_std_event_test.hpp>

using ls_std_event_test::GossipNewsAgency;
using ls::std::event::EventManager;
using ::std::shared_ptr;
using ::std::make_shared;

namespace
{
  class EventManagerTest : public ::testing::Test
  {
    protected:

      EventManagerTest() = default;
      ~EventManagerTest() override = default;

      shared_ptr<GossipNewsAgency> gossipNewsAgency = make_shared<GossipNewsAgency>();
      shared_ptr<EventManager> eventManager = make_shared<EventManager>();

      void SetUp() override
      {

      }

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
    EXPECT_THROW(
{
             try
             {
               EventManager eventManager{};
               std::function<void(ls::std::event::Event)> listener = std::bind(&GossipNewsAgency::onGossipNews, gossipNewsAgency, ::std::placeholders::_1);
               eventManager.subscribe("", listener);
             }
             catch (const ls::std::core::IllegalArgumentException &_exception)
             {
               throw;
             }
          }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, subscribe_no_listener)
  {
    EXPECT_THROW(
{
             try
             {
               EventManager eventManager{};
               eventManager.subscribe("TMP_ID", nullptr);
             }
             catch (const ls::std::core::IllegalArgumentException &_exception)
             {
               throw;
             }
          }, ls::std::core::IllegalArgumentException);
  }


  TEST_F(EventManagerTest, unsubscribe_empty_id)
  {
    EXPECT_THROW({
                   try
                   {
                     EventManager eventManager{};
                     std::function<void(ls::std::event::Event)> listener = std::bind(&GossipNewsAgency::onGossipNews, gossipNewsAgency, ::std::placeholders::_1);
                     eventManager.unsubscribe("", listener);
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
                     EventManager eventManager{};
                     eventManager.unsubscribe("TMP_ID", nullptr);
                   }
                   catch (const ls::std::core::IllegalArgumentException &_exception)
                   {
                     throw;
                   }
                 }, ls::std::core::IllegalArgumentException);
  }

  TEST_F(EventManagerTest, production_example)
  {

  }

//  TEST_F(EventManagerTest, production_example)
//  {
//    ::std::string news, expectedNews{};
//    ls::std::core::type::event_id seriousNewsEventId = ls_std_event_test::SeriousNewsEvent{""}.getId();
//    ls::std::core::type::event_id gossipNewsEventId = ls_std_event_test::GossipNewsEvent{""}.getId();
//
//    // create event handler
//
//    ::std::shared_ptr<ls::std::event::EventHandler> seriousNewsEventHandler = ::std::make_shared<ls::std::event::EventHandler>(seriousNewsEventId);   // event id
//    ::std::shared_ptr<ls::std::event::EventHandler> gossipNewsEventHandler = ::std::make_shared<ls::std::event::EventHandler>(gossipNewsEventId);     // event id
//
//    // create and fill event manager with handler
//
//    ::std::shared_ptr<ls::std::event::EventManager> eventManager = ::std::make_shared<ls::std::event::EventManager>();
//    eventManager->addEventHandler(seriousNewsEventHandler);
//    eventManager->addEventHandler(gossipNewsEventHandler);
//
//    // create news agency (listener)
//
//    ::std::shared_ptr<ls_std_event_test::DailyNewsAgency> dailyNews = ::std::make_shared<ls_std_event_test::DailyNewsAgency>();
//    ::std::shared_ptr<ls_std_event_test::GossipNewsAgency> gossipNews = ::std::make_shared<ls_std_event_test::GossipNewsAgency>();
//
//    // fire SeriousNewsEvent event with no effect
//
//    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call
//    ASSERT_TRUE(dailyNews->getNews().empty());
//    ASSERT_TRUE(gossipNews->getNews().empty());
//
//    // now subscribe to SeriousNewsEvent and fire SeriousNewsEvent event
//
//    //eventManager->subscribe(seriousNewsEventId, dailyNews->onSeriousNews);
//    //eventManager->subscribe(seriousNewsEventId, gossipNews->onSeriousNews);
//    news = "COVID-19 is still going on!";
//    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call
//
//    expectedNews = "DailyNewsAgency: " + news;
//    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
//    expectedNews = "GossipNewsAgency: " + news;
//    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
//
//    dailyNews->clear();
//    gossipNews->clear();
//
//    // unsubscribe SeriousNewsEvent from GossipNewsAgency
//
//    //eventManager->unsubscribe(seriousNewsEventId, gossipNews->onSeriousNews);
//    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call
//
//    expectedNews = "DailyNewsAgency: " + news;
//    ASSERT_STREQ(expectedNews.c_str(), dailyNews->getNews().c_str());
//    ASSERT_TRUE(gossipNews->getNews().empty());
//
//    dailyNews->clear();
//    gossipNews->clear();
//
//    // now let GossipNewsAgency subscribe to SeriousNewsEvent + GossipNewsEvent and fire both of them
//
//    std::function<void(ls::std::event::Event)> listener = ::std::bind(&ls_std_event_test::GossipNewsAgency::onGossipNews, gossipNews, ::std::placeholders::_1);
//    eventManager->subscribe(gossipNewsEventId, listener);
//    //eventManager->subscribe(seriousNewsEventId, gossipNews->onSeriousNews);
//
//    news = "COVID-19 is still going on!";
//    eventManager->fire(ls_std_event_test::SeriousNewsEvent(news)); // event call
//    expectedNews = "GossipNewsAgency: " + news;
//    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
//
//    news = "ape likes banana!";
//    eventManager->fire(ls_std_event_test::GossipNewsEvent(news)); // event call
//    expectedNews = "GossipNewsAgency: " + news;
//    ASSERT_STREQ(expectedNews.c_str(), gossipNews->getNews().c_str());
//  }
//
//
//  TEST_F(EventManagerTest, ListenerTest)
//  {
//    ::std::shared_ptr<ls_std_event_test::GossipNewsAgency> gossipNews = ::std::make_shared<ls_std_event_test::GossipNewsAgency>();
//    ls::std::core::type::event_id gossipNewsEventId = ls_std_event_test::GossipNewsEvent{""}.getId();
//    ::std::shared_ptr<ls::std::event::EventManager> eventManager = ::std::make_shared<ls::std::event::EventManager>();
//    std::function<void(ls::std::event::Event)> listener = ::std::bind(&ls_std_event_test::GossipNewsAgency::onGossipNews, gossipNews, ::std::placeholders::_1);
//    eventManager->subscribe(gossipNewsEventId, listener);
//    ::std::string news = "ape likes banana!";
//    eventManager->fire(ls_std_event_test::GossipNewsEvent(news)); // event call
//  }
}
