/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-05-01
 *
 * */

#include <ls_std/factory/serialization/json/SerializableJSONFactory.hpp>
#include <ls_std/boxing/Boolean.hpp>
#include <ls_std/boxing/Double.hpp>
#include <ls_std/boxing/Float.hpp>
#include <ls_std/boxing/Integer.hpp>
#include <ls_std/boxing/Long.hpp>
#include <ls_std/boxing/String.hpp>
#include <ls_std/factory/serialization/json/boxing/SerializableJSONBooleanFactory.hpp>
#include <ls_std/factory/serialization/json/boxing/SerializableJSONDoubleFactory.hpp>
#include <ls_std/factory/serialization/json/boxing/SerializableJSONFloatFactory.hpp>
#include <ls_std/factory/serialization/json/boxing/SerializableJSONIntegerFactory.hpp>
#include <ls_std/factory/serialization/json/boxing/SerializableJSONLongFactory.hpp>
#include <ls_std/factory/serialization/json/boxing/SerializableJSONStringFactory.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>
#include <ls_std/exception/NullPointerException.hpp>

ls_std::SerializableJSONFactory::SerializableJSONFactory() : ls_std::Class("SerializableJSONFactory")
{
  this->_init();
}

bool ls_std::SerializableJSONFactory::addFactory(const std::pair<std::string, std::shared_ptr<ls_std::IFactory>> &_factoryInsertion)
{
  bool factoryAdded{};

  if (_factoryInsertion.first.empty())
  {
    throw ls_std::IllegalArgumentException{};
  }

  if (_factoryInsertion.second == nullptr)
  {
    throw ls_std::NullPointerException{};
  }

  if (!this->_hasFactory(_factoryInsertion.first))
  {
    factoryAdded = this->factories.insert(_factoryInsertion).second;
  }

  return factoryAdded;
}

std::shared_ptr<ls_std::Class> ls_std::SerializableJSONFactory::build(const std::string &_relatedObjectName)
{
  std::shared_ptr<ls_std::Class> requestedBuiltObject{};

  if (this->_hasFactory(_relatedObjectName))
  {
    requestedBuiltObject = this->factories.at(_relatedObjectName)->build();
  }

  return requestedBuiltObject;
}

bool ls_std::SerializableJSONFactory::clear()
{
  this->factories.clear();
  return factories.empty();
}

bool ls_std::SerializableJSONFactory::hasFactory(const std::string &_relatedObjectName)
{
  return this->_hasFactory(_relatedObjectName);
}

bool ls_std::SerializableJSONFactory::removeFactory(const std::string &_relatedObjectName)
{
  bool wasRemoved{};

  if (this->_hasFactory(_relatedObjectName))
  {
    this->factories.erase(_relatedObjectName);
    wasRemoved = !this->_hasFactory(_relatedObjectName);
  }

  return wasRemoved;
}

bool ls_std::SerializableJSONFactory::_hasFactory(const std::string &_relatedObjectName)
{
  return this->factories.find(_relatedObjectName) != this->factories.end();
}

void ls_std::SerializableJSONFactory::_init()
{
  this->factories.insert({ls_std::Boolean{}.getClassName(), std::make_shared<ls_std::SerializableJSONBooleanFactory>()});
  this->factories.insert({ls_std::Double{}.getClassName(), std::make_shared<ls_std::SerializableJSONDoubleFactory>()});
  this->factories.insert({ls_std::Float{}.getClassName(), std::make_shared<ls_std::SerializableJSONFloatFactory>()});
  this->factories.insert({ls_std::Integer{}.getClassName(), std::make_shared<ls_std::SerializableJSONIntegerFactory>()});
  this->factories.insert({ls_std::Long{}.getClassName(), std::make_shared<ls_std::SerializableJSONLongFactory>()});
  this->factories.insert({ls_std::String{}.getClassName(), std::make_shared<ls_std::SerializableJSONStringFactory>()});
}
