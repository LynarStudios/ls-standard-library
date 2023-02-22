/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-22
*
* */

#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/core/exception/IndexOutOfBoundsException.hpp>

ls::std::core::IndexOutOfBoundsEvaluator::IndexOutOfBoundsEvaluator(size_t _index, size_t _size) : index(_index), size(_size)
{}

ls::std::core::IndexOutOfBoundsEvaluator::IndexOutOfBoundsEvaluator(size_t _index, size_t _size, ::std::string _message) : index(_index), size(_size), message(::std::move(_message))
{}

ls::std::core::IndexOutOfBoundsEvaluator::~IndexOutOfBoundsEvaluator() noexcept = default;

void ls::std::core::IndexOutOfBoundsEvaluator::evaluate()
{
  if (this->index >= this->size)
  {
    if (this->message.empty())
    {
      throw ls::std::core::IndexOutOfBoundsException{};
    }
    else
    {
      throw ls::std::core::IndexOutOfBoundsException{this->message};
    }
  }
}
