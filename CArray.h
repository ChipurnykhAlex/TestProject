#pragma once
#include "CArrayIterator.h"

#define CARRAY_DEFAULT_CAPACITY 32

template <typename TData>
class CArray
{
public:
  CArray() 
    : array_capacity(CARRAY_DEFAULT_CAPACITY),
    array_size(0)
  {
    array = new TData[array_capacity];
  }

  CArray(
      const CArray& _array
    )
      : array_capacity(_array.capacity()),
        array_size(_array.size())
  {
    array = new TData[array_capacity];
    
    for (unsigned int i = 0; i < array_size; i++)
    {
      array[i] = _array[i];
    }
  }

  ~CArray()
  {
    delete array;
  }

  void push_pack(
      const TData& _value
    )
  {
    if (array_size == array_capacity)
    {
      resize_array(array_capacity * 2);
    }
    array[array_size] = _value;
    array_size++;
  }

  void insert(
      unsigned int _index,
      const TData& _value
    )
  {
    if (_index > array_size)
    {
      std::cout << "Error insert: out if range\n";
      return;
    }

    if (_index == array_size)
    {
      push_pack(_value);
    }
    else
    {
      if (array_size == array_capacity)
      {
        resize_array(array_capacity * 2);
      }

      for (unsigned int i = array_size; i > _index; i--)
      {
        array[i] = array[i - 1];
      }
      array[_index] = _value;
      array_size++;
    }
  }


  void erase(
      unsigned int _index
    )
  {
    if (_index >= array_size)
    {
      std::cout << "Error erase: out if range\n";
      return;
    }
    for (unsigned int i = _index; i < array_size; i++)
    {
      array[i] = array[i + 1];
    }
    array_size--;
  }

  
  void clear()
  {
    array_size = 0;
  }

  unsigned int capacity() const 
  {
    return array_capacity;
  }

  unsigned int size() const 
  {
    return array_size;
  }

  TData & operator[](
    unsigned int _index
    ) 
  {
    if (_index >= array_size)
    {
      std::cout << "Error operator[]: out if range\n";
      return array[0];
    }

    return array[_index];
  }

  TData & operator[](
    unsigned int _index
    ) const
  {
    if (_index >= array_size)
    {
      std::cout << "Error operator[]: out if range\n";
      return array[0];
    }
    return array[_index];
  }

  TData& operator-() const
  {
    return -TData;
  }

public:
  CArrayIterator<TData> begin()
  {
    return CArrayIterator<TData>(array);
  }

  CArrayIterator<TData> end()
  {
    return CArrayIterator<TData>(array + array_size);
  }

  
  CArrayIterator<const TData> begin() const
  {
    return CArrayIterator<const TData>(array);
  }

  CArrayIterator<const TData> end() const
  {
    return CArrayIterator<const TData>(array + array_size);
  }
  
  void sort()
  {
    bool b = true;
    int sz = array_size;
    while (b) {
      b = false;
      for (int i = 0; i < sz - 1; i++)
      {
        if (i >= 0 && array[i] > array[i + 1])
        {
          std::swap(array[i], array[i + 1]);
          b = true;
        }
      }
      sz--;
    }
  }

private:

  void resize_array(
      unsigned int new_capacity
    )
  {
    array_capacity = new_capacity;
    TData* new_array = new TData[array_capacity];
    memcpy(new_array, array, sizeof(TData)*array_capacity);
    delete array;
    array = new_array;
  }

private:
  TData* array;
  unsigned int array_capacity;
  unsigned int array_size;

};
