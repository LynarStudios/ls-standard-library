/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-01
 *
 * */

#include <ls_std/factory/serialization/boxing/SerializableJSONLongFactory.hpp>
#include <ls_std/boxing/Long.hpp>
#include <ls_std/serialization/json/boxing/SerializableJSONLong.hpp>

ls_std::SerializableJSONLongFactory::SerializableJSONLongFactory() : ls_std::Class("SerializableJSONLongFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONLongFactory::build()
{
  std::shared_ptr<ls_std::Long> requestedObject = std::make_shared<ls_std::Long>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONLong>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
