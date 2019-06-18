///////////////////////////////////////////////////////////////
// Set.cpp - demonstrating STL std::set<T> container         //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include <set>
#include <string>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("set<string>");
  /*
  * Implements ordered collection of elements with each element stored
  * independently in the native heap.  Sets are based on the red-black
  * binary tree, so its contents are ordered.  Insertion, retrieval, and
  * removal are log n time.
  */
  std::set<std::string> setStr{ "first", "second", "third", "fourth", "fifth", "sixth" };
  std::cout << show(setStr);

  /* find is order log n */
  std::string element = "fourth";
  std::set<std::string>::iterator iter = setStr.find(element);
  if (iter != end(setStr))
    std::cout << "\n  found element " << *iter;
  else
    std::cout << "\n  didn't find element " << element;
  element = "foobar";
  iter = setStr.find(element);
  if (iter != end(setStr))
    std::cout << "\n  found element " << *iter;
  else
    std::cout << "\n  didn't find element " << element;

  /* insertion is order log n */
  iter = setStr.insert(iter, element);  // expects hint iterator
  std::cout << "\n  inserted " << *iter;
  
  element = "feebar";
  auto result = setStr.insert(element);
  if (result.second)
    std::cout << "\n  inserted " << element;
  else
    std::cout << "\n  insertion failed for " << element;
  
  /* attempt to insert value already in set will fail */
  result = setStr.insert(element);
  if (result.second)
    std::cout << "\n  inserted element" << element;
  else
    std::cout << "\n  insertion failed for " << element;
  std::cout << show(setStr);
  
  /* removal is log n complexity */
  element = "fourth";
  int numRemoved = setStr.erase(element);
  std::cout << "\n  removed element " << element;
  std::cout << show(setStr);

  std::cout << "\n\n";
}