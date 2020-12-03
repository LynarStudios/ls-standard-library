/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-11-26
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_EVENT_TYPES_HPP
#define LS_STD_EVENT_TYPES_HPP

#include <string>
#include <vector>
#include <map>

namespace ls_std {
  using event_id = std::string;
  using event_parameter_id = std::string;
  using event_parameter_value = std::string;
  using event_parameter = std::pair<std::string, std::string>;
  using event_parameter_list = std::map<event_parameter_id, event_parameter_value>;
}

#endif
