/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-14
 * Changed:         2023-02-06
 *
 * */

#ifndef LS_STD_NARRATOR_HPP
#define LS_STD_NARRATOR_HPP

#include <list>
#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IListener.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::event
{
  class LS_STD_DYNAMIC_GOAL Narrator : public ls::std::core::Class
  {
    public:

      Narrator();
      ~Narrator() override;

      bool addListener(const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener); // nodiscard is optional here
      void clear();
      [[nodiscard]] ::std::list<::std::shared_ptr<ls::std::core::interface_type::IListener>> getListeners();
      bool removeListener(const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener); // nodiscard is optional here
      void tell(const ls::std::core::Class &_info);

    private:

      ::std::list<::std::shared_ptr<ls::std::core::interface_type::IListener>> listeners{};

      [[nodiscard]] bool _hasListener(const ::std::shared_ptr<ls::std::core::interface_type::IListener> &_listener);
  };
}

#endif
