/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/core/exception/IndexOutOfBoundsException.hpp>

using ls::std::core::IndexOutOfBoundsEvaluator;
using ls::std::core::IndexOutOfBoundsException;
using std::move;
using std::string;

IndexOutOfBoundsEvaluator::IndexOutOfBoundsEvaluator(size_t _index, size_t _size) : index(_index), size(_size)
{}

IndexOutOfBoundsEvaluator::IndexOutOfBoundsEvaluator(size_t _index, size_t _size, string _message) : index(_index), size(_size), message(::move(_message))
{}

IndexOutOfBoundsEvaluator::~IndexOutOfBoundsEvaluator() noexcept = default;

void IndexOutOfBoundsEvaluator::evaluate()
{
  if (this->index >= this->size)
  {
    if (this->message.empty())
    {
      throw IndexOutOfBoundsException{};
    }
    else
    {
      throw IndexOutOfBoundsException{this->message};
    }
  }
}
