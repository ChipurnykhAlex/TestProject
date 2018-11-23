#pragma once

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
      const TData& _array
    ) 
    : array_capacity(CARRAY_DEFAULT_CAPACITY),
      array_size(0)
  {
    array = new TData[array_capacity];
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
      
      for (size_t i = array_size; i > _index; i--)
      {
        array[i + 1] = array[i];
      }
      array[_index] = _value;
    }
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
    return array[_index];
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

