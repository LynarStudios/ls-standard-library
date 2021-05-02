/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/factory/serialization/json/boxing/SerializableJsonIntegerFactory.hpp>
#include <ls_std/boxing/Integer.hpp>
#include <ls_std/serialization/json/boxing/SerializableJsonInteger.hpp>

ls_std::SerializableJsonIntegerFactory::SerializableJsonIntegerFactory() : ls_std::Class("SerializableJsonIntegerFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJsonIntegerFactory::build()
{
  std::shared_ptr<ls_std::Integer> requestedObject = std::make_shared<ls_std::Integer>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJsonInteger>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
