/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-30
 * Changed:         2021-05-01
 *
 * */

#include <ls_std/factory/serialization/event/SerializableJSONEventFactory.hpp>
#include <ls_std/event/Event.hpp>
#include <ls_std/serialization/json/event/SerializableJSONEvent.hpp>

ls_std::SerializableJSONEventFactory::SerializableJSONEventFactory() : ls_std::Class("SerializableJSONEventFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONEventFactory::build()
{
  std::shared_ptr<ls_std::Event> requestedObject = std::make_shared<ls_std::Event>("TMP_ID");
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONEvent>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
