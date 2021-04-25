/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-25
 * Changed:         2021-04-25
 *
 * */

#include <ls_std/factory/serialization/boxing/SerializableJSONIntegerFactory.hpp>
#include <ls_std/boxing/Integer.hpp>
#include <ls_std/serialization/boxing/SerializableJSONInteger.hpp>

ls_std::SerializableJSONIntegerFactory::SerializableJSONIntegerFactory() : ls_std::Class("SerializableJSONIntegerFactory")
{}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONIntegerFactory::build()
{
  std::shared_ptr<ls_std::Integer> value = std::make_shared<ls_std::Integer>();
  std::shared_ptr<ls_std::ISerializable> serializable = std::make_shared<ls_std::SerializableJSONInteger>(value);
  value->setSerializable(serializable);

  return std::dynamic_pointer_cast<ls_std::Class>(value);
}
