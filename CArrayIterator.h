#pragma once
#include <iterator>

template <typename T>
class CArrayIterator: public std::iterator<std::input_iterator_tag, T>
{
public:
  CArrayIterator(
    T* _p
  ) 
    :p(_p)
  {
  }


  CArrayIterator(
    const CArrayIterator& _it
  )
    :p(_it.p)
  {
  }

  bool operator!=(
    const CArrayIterator& _iterator
    )
  {
    return p != _iterator.p;
  }

  bool operator==(
    const CArrayIterator& _iterator
    )
  {
    return p == _iterator.p;
  }

  typename CArrayIterator::reference operator*() const 
  {
    return *p;
  }
  
  CArrayIterator& operator++()
  {
    ++p;
    return *this;
  }

  CArrayIterator& operator--()
  {
    --p;
    return *this;
  }

private:
  T* p;
};

