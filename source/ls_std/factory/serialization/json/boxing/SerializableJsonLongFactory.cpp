/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/factory/serialization/json/boxing/SerializableJsonLongFactory.hpp>
#include <ls_std/boxing/Long.hpp>
#include <ls_std/serialization/json/boxing/SerializableJsonLong.hpp>

ls_std::SerializableJsonLongFactory::SerializableJsonLongFactory() : ls_std::Class("SerializableJsonLongFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJsonLongFactory::build()
{
  std::shared_ptr<ls_std::Long> requestedObject = std::make_shared<ls_std::Long>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJsonLong>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
