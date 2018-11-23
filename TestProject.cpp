
#include "pch.h"
#include <iostream>
#include "CArray.h"

int main()
{
  std::cout << "Hello World!\n";

  CArray<int>* array = new CArray<int>(50);

  //std::cout << array->test(80);
  int a = 0;

  delete array;
}
