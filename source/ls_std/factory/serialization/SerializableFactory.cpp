/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-04-24
 * Changed:         2021-04-24
 *
 * */

#include <ls_std/factory/serialization/SerializableFactory.hpp>
#include <ls_std/boxing/Boolean.hpp>
#include <ls_std/factory/serialization/boxing/SerializableJSONBooleanFactory.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>
#include <ls_std/exception/NullPointerException.hpp>

ls_std::SerializableFactory::SerializableFactory() : ls_std::Class("SerializableFactory")
{
  this->_init();
}

bool ls_std::SerializableFactory::addFactory(const std::pair<std::string, std::shared_ptr<ls_std::IFactory>> &_factoryInsertion)
{
  bool hasFactory{};

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
    hasFactory = this->factories.insert(_factoryInsertion).second;
  }

  return hasFactory;
}

std::shared_ptr<ls_std::Class> ls_std::SerializableFactory::build(const std::string &_relatedObjectName)
{
  std::shared_ptr<ls_std::Class> requestedObject{};

  if (this->_hasFactory(_relatedObjectName))
  {
    requestedObject = this->factories.at(_relatedObjectName)->build();
  }

  return requestedObject;
}

bool ls_std::SerializableFactory::clear()
{
  this->factories.clear();
  return factories.empty();
}

bool ls_std::SerializableFactory::hasFactory(const std::string &_relatedObjectName)
{
  return this->_hasFactory(_relatedObjectName);
}

bool ls_std::SerializableFactory::removeFactory(const std::string &_relatedObjectName)
{
  bool wasRemoved{};

  if (this->_hasFactory(_relatedObjectName))
  {
    this->factories.erase(_relatedObjectName);
    wasRemoved = !this->_hasFactory(_relatedObjectName);
  }

  return wasRemoved;
}

bool ls_std::SerializableFactory::_hasFactory(const std::string &_relatedObjectName)
{
  return this->factories.find(_relatedObjectName) != this->factories.end();
}

void ls_std::SerializableFactory::_init()
{
  this->factories.insert({ls_std::Boolean{}.getClassName(), std::make_shared<ls_std::SerializableJSONBooleanFactory>()});
}
