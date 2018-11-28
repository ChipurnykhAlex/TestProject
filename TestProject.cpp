#include "pch.h"
#include <iostream>
#include "CArray.h"
#include <time.h>
#include <algorithm>

void showResult(CArray<int>* array)
{
  std::cout << "array size = ";
  std::cout << array->size();
  std::cout << "\n";
  int cnt = 0;
  for (CArrayIterator<int> it = array->begin(); it != array->end(); ++it)
  {
    std::cout << cnt;
    std::cout << " - ";
    std::cout << (*it);
    std::cout << "\n";
    cnt++;
  }
}

void showResultString(CArray<std::string>* array)
{
  std::cout << "array size = ";
  std::cout << array->size();
  std::cout << "\n";
  int cnt = 0;
  for (CArrayIterator<std::string> it = array->begin(); it != array->end(); ++it)
  {
    std::cout << cnt;
    std::cout << " - ";
    std::cout << (*it).c_str();
    std::cout << "\n";
    cnt++;
  }
}

std::string getRandomString()
{
  char chars[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u' };

  std::string str;
  for (size_t i = 0; i < 5; i++)
  {
    str += chars[rand() % 20];
  }

  return str;
}

int main()
{
  std::cout << "Test 1\n";

  std::srand(size_t(time(0)));
  

  CArray<int>* array = new CArray<int>();

  std::cout << "Test 1.1\n";
  for (size_t i = 0; i < 20; i++)
  {
    array->push_pack(rand() % 100);
  }
  showResult(array);
  
  std::cout << "Test 1.2\n";
  array->sort();
  
  showResult(array);

  std::cout << "Test 1.3\n";
  int size = array->size() / 2;
  for (int i = 1; i <= size; i++)
  {
    array->erase(i);
  }

  showResult(array);

  std::cout << "Test 1.4\n";

  for (size_t i = 0; i < 10; i++)
  {
    int val = rand() % 100;
    int index = rand() % array->size();
    array->insert(index, val);
  }

  showResult(array);

  std::cout << "Test 1.5\n";

  array->clear();

  showResult(array);

  std::cout << "\n";
  std::cout << "Test 1\n";
  std::cout << "Test 2.1\n";

  CArray<std::string>* stringArray = new CArray<std::string>();
  for (size_t i = 0; i < 15; i++)
  {
    stringArray->push_pack(getRandomString());
  }

  showResultString(stringArray);

  std::cout << "Test 2.2\n";
  stringArray->sort();

  showResultString(stringArray);

  std::cout << "Test 2.3\n";
  
  char chars[] = { 'a', 'b', 'c', 'd', 'e'};

  bool b = b = true;
  while (b)
  {
    b = false;
    for (size_t i = 0; i < stringArray->size(); i++)
    {
      for (size_t j = 0; j < 5; j++)
      {
        std::string str = (*stringArray)[i];
        int result = str.find(chars[j]);
        if (result != -1)
        {
          stringArray->erase(i);
          b = true;
          break;
        }
      }
    }
  }

  showResultString(stringArray);

  std::cout << "Test 2.4\n";

  for (size_t i = 0; i < 3; i++)
  {
    std::string str = getRandomString();
    if (stringArray->size() == 0)
      stringArray->push_pack(str);
    else
    {
      int index = rand() % stringArray->size();
      stringArray->insert(index, str);
    }
  }

  showResultString(stringArray);

  delete array;
}
