/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/factory/serialization/json/boxing/SerializableJsonStringFactory.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/serialization/json/boxing/SerializableJsonString.hpp>

ls_std::SerializableJsonStringFactory::SerializableJsonStringFactory() : ls_std::Class("SerializableJsonStringFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJsonStringFactory::build()
{
  std::shared_ptr<ls_std::String> requestedObject = std::make_shared<ls_std::String>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJsonString>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
