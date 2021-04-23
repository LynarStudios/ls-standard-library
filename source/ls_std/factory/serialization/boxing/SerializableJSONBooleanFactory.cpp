/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/factory/serialization/boxing/SerializableJSONBooleanFactory.hpp>
#include <ls_std/boxing/Boolean.hpp>
#include <ls_std/serialization/boxing/SerializableJSONBoolean.hpp>

ls_std::SerializableJSONBooleanFactory::SerializableJSONBooleanFactory() : ls_std::Class("SerializableJSONBooleanFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONBooleanFactory::build()
{
  std::shared_ptr<ls_std::Boolean> value = std::make_shared<ls_std::Boolean>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONBoolean>(value);
  value->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(value);
}
