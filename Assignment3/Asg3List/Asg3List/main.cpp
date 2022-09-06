//
//  main.cpp
//  testlist
//
//  Created by Anastasia Tuttle  on 9/5/22.
//
//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "List.h"

void printItem(int &item) {
  std::cout << item << " ";
}

int main() {
  List<int> aListOfIntegers;
  if (aListOfIntegers.empty()) {
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 3; i >= 0; i--) {
    aListOfIntegers.push_front(i);
  }
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  std::cout << "Test iterators: Mutable -> ";
  for (auto iter = aListOfIntegers.begin();
            iter != aListOfIntegers.end();
            ++iter) {
              std::cout << *iter << " ";
            }

   std::cout << "Test iterators: const -> ";
  for (auto iter = aListOfIntegers.cbegin();
            iter != aListOfIntegers.cend();
            ++iter) {
              std::cout << *iter << " ";
            }
    std::cout<<"Test iterators: rbegin and rend: " ;
    for (auto iter = aListOfIntegers.rbegin();
         iter != aListOfIntegers.rend();
         ++iter)
        {
            std::cout << *iter << " ";
        }
    std::cout<<"Test iterators: crbegin and crend: ";
    for (auto iter = aListOfIntegers.crbegin();
         iter != aListOfIntegers.crend();
         ++iter)
    {
        std::cout << *iter << " ";
    }
  
  std::cout << std::endl;
  for (int i = 0; i < 3; i++) {
    int datum = aListOfIntegers.back();
    std::cout << datum << " ";
    aListOfIntegers.pop_back();
  }
  std::cout << std::endl;
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
  }
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  return 0;
}
