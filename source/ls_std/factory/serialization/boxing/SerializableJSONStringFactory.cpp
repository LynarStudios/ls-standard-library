/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-04-25
 *
 * */

#include <ls_std/factory/serialization/boxing/SerializableJSONStringFactory.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/serialization/boxing/SerializableJSONString.hpp>

ls_std::SerializableJSONStringFactory::SerializableJSONStringFactory() : ls_std::Class("SerializableJSONStringFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONStringFactory::build()
{
  std::shared_ptr<ls_std::String> value = std::make_shared<ls_std::String>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONString>(value);
  value->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(value);
}
