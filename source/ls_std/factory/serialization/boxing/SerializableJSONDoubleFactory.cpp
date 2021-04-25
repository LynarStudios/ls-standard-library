/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-04-24
 *
 * */

#include <ls_std/factory/serialization/boxing/SerializableJSONDoubleFactory.hpp>
#include <ls_std/boxing/Double.hpp>
#include <ls_std/serialization/boxing/SerializableJSONDouble.hpp>

ls_std::SerializableJSONDoubleFactory::SerializableJSONDoubleFactory() : ls_std::Class("SerializableJSONDoubleFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONDoubleFactory::build()
{
  std::shared_ptr<ls_std::Double> value = std::make_shared<ls_std::Double>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONDouble>(value);
  value->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(value);
}
