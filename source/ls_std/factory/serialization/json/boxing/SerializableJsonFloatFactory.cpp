/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/factory/serialization/json/boxing/SerializableJsonFloatFactory.hpp>
#include <ls_std/boxing/Float.hpp>
#include <ls_std/serialization/json/boxing/SerializableJsonFloat.hpp>

ls_std::SerializableJsonFloatFactory::SerializableJsonFloatFactory() : ls_std::Class("SerializableJsonFloatFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJsonFloatFactory::build()
{
  std::shared_ptr<ls_std::Float> requestedObject = std::make_shared<ls_std::Float>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJsonFloat>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
