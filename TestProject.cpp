#include "pch.h"
#include <iostream>
#include "CArray.h"
#include <time.h>
#include <algorithm>

int main()
{
  std::cout << "Test 1\n";

  std::srand(size_t(time(0)));

  CArray<int>* array = new CArray<int>();

  std::cout << "Test 1.1\n";
  for (size_t i = 0; i < 10; i++)
  {
    array->push_pack(rand() % 100);
  }
  int cnt = 0;
  for (CArrayIterator<int> it = array->begin(); it != array->end(); ++it)
  {
    std::cout << cnt;
    std::cout << " - ";
    std::cout << (*it);
    std::cout << "\n";
    cnt++;
  }
  std::cout << "Test 1.2\n";
  std::sort(array->begin(), array->end(), std::greater<int>());
  //std::qsort(&array->begin(), array->size(), array->size() * sizeof(int), NULL);

  cnt = 0;
  for (CArrayIterator<int> it = array->begin(); it != array->end(); ++it)
  {
    std::cout << cnt;
    std::cout << " - ";
    std::cout << (*it);
    std::cout << "\n";
    cnt++;
  }

  /*
  array->push_pack(20);
  array->push_pack(5);
  array->insert(1, 13);
  */
  /*
  CArray<int>* arr1 = new CArray<int>(*array);
  arr1->push_pack(44);
  arr1->erase(2);
  
  for (CArrayIterator<int> it = arr1->begin(); it != arr1->end(); ++it)
  {
    std::cout << cnt;
    std::cout << " - ";
    std::cout << (*it);
    std::cout << "\n";
    cnt++;
  }
  */
  
  array->clear();

  delete array;

  //delete arr1;
}
