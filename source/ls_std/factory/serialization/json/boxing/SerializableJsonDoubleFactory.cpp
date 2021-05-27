/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/factory/serialization/json/boxing/SerializableJsonDoubleFactory.hpp>
#include <ls_std/boxing/Double.hpp>
#include <ls_std/serialization/json/boxing/SerializableJsonDouble.hpp>

ls_std::SerializableJsonDoubleFactory::SerializableJsonDoubleFactory() : ls_std::Class("SerializableJsonDoubleFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJsonDoubleFactory::build()
{
  std::shared_ptr<ls_std::Double> requestedObject = std::make_shared<ls_std::Double>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJsonDouble>(requestedObject);
  requestedObject->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(requestedObject);
}
