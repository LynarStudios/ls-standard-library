/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-04-30
 *
 * */

#include <ls_std/factory/serialization/boxing/SerializableJSONFloatFactory.hpp>
#include <ls_std/boxing/Float.hpp>
#include <ls_std/serialization/boxing/SerializableJSONFloat.hpp>

ls_std::SerializableJSONFloatFactory::SerializableJSONFloatFactory() : ls_std::Class("SerializableJSONFloatFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONFloatFactory::build()
{
  std::shared_ptr<ls_std::Float> requestedObject = std::make_shared<ls_std::Float>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONFloat>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
