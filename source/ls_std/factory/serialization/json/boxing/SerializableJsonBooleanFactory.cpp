/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-23
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/factory/serialization/json/boxing/SerializableJsonBooleanFactory.hpp>
#include <ls_std/boxing/Boolean.hpp>
#include <ls_std/serialization/json/boxing/SerializableJsonBoolean.hpp>

ls_std::SerializableJsonBooleanFactory::SerializableJsonBooleanFactory() : ls_std::Class("SerializableJsonBooleanFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJsonBooleanFactory::build()
{
  std::shared_ptr<ls_std::Boolean> requestedObject = std::make_shared<ls_std::Boolean>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJsonBoolean>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
