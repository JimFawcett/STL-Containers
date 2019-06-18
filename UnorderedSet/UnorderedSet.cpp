///////////////////////////////////////////////////////////////////////////
// UnorderedSet.cpp - demonstrating STL std::unordered_set<T> container  //
//                                                                       //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014             //
///////////////////////////////////////////////////////////////////////////

#include <unordered_set>
#include <string>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("unordered_set<string>");
  /*
  * Implements unordered collection of elements with each element stored
  * independently in the native heap with pointer saved in some bucket in a table.
  *
  * The table address of the bucket is determined by computing a hash of the
  * value to be stored.  The Hashed address is not guaranteed to be unique,
  * so any bucket may contain a linked list of values with the same hash.
  * A good hash function generates a nearly uniform distribution of addresses
  * across the table, which tends to keep the list length short, usually 0 or 1.
  *
  * Since unordered_sets are based on a hash-table, their contents are unordered.
  * Insertion, retrieval, and removal are constant time.
  */
  std::unordered_set<std::string> u_setStr{ "first", "second", "third", "fourth", "fifth", "sixth" };
  std::cout << show(u_setStr);

  /* find is constant time */
  std::string element = "fourth";
  std::unordered_set<std::string>::iterator iter = u_setStr.find(element);
  if (iter != end(u_setStr))
    std::cout << "\n  found element " << *iter;
  else
    std::cout << "\n  didn't find element " << element;
  element = "foobar";
  iter = u_setStr.find(element);
  if (iter != end(u_setStr))
    std::cout << "\n  found element " << *iter;
  else
    std::cout << "\n  didn't find element " << element;

  /* insertion is order log n */
  iter = u_setStr.insert(iter, element);  // expects hint iterator
  std::cout << "\n  inserted " << *iter;

  element = "feebar";
  auto result = u_setStr.insert(element);
  if (result.second)
    std::cout << "\n  inserted " << element;
  else
    std::cout << "\n  insertion failed for " << element;

  /* attempt to insert value already in set will fail */
  result = u_setStr.insert(element);
  if (result.second)
    std::cout << "\n  inserted element" << element;
  else
    std::cout << "\n  insertion failed for " << element;
  std::cout << show(u_setStr);

  /* removal is constant time */
  element = "fourth";
  int numRemoved = u_setStr.erase(element);
  std::cout << "\n  removed element " << element;
  std::cout << show(u_setStr);
  std::wcout << std::endl;

  /* demonstrate hashing */
  std::cout << "\n  demonstrating hash<double>:";
  std::unordered_set<double> usetDbl{ 1.0, 3.1415927, 1.5e-4, -1.0 / 3.0 };
  std::cout << show(usetDbl);
  std::cout << "\n  size = " << usetDbl.size();
  std::cout << ", max_bucket_count = " << usetDbl.max_bucket_count() << ", load_factor = " << usetDbl.load_factor();
  std::cout << std::endl;
  std::unordered_set<double> more{ 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5 };
  std::cout << show(more);
  std::cout << "\n  size = " << more.size();
  std::cout << ", max_bucket_count = " << more.max_bucket_count() << ", load_factor = " << more.load_factor();
  std::cout << std::endl;

  double value = 10.5;
  std::cout << "\n  inserting " << value;
  more.insert(value);
  std::cout << show(more);
  std::cout << "\n  size = " << more.size();
  std::cout << ", max_bucket_count = " << more.max_bucket_count() << ", load_factor = " << more.load_factor();
  std::cout << std::endl;

  std::cout << "\n  demonstrating hash<std::string>:";
  std::unordered_set<std::string> usetStr{ "one", "two", "three", "four" };
  std::cout << show(usetStr);
  std::cout << "\n  size = " << usetStr.size();
  std::cout << ", max_bucket_count = " << usetStr.max_bucket_count() << ", load_factor = " << usetStr.load_factor();

  std::cout << "\n\n";
}