/////////////////////////////////////////////////////////////////////////////
// UnorderedMap.cpp - demonstrating STL std::unordered_map<K,V> container  //
//                                                                         //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014               //
/////////////////////////////////////////////////////////////////////////////

#include <unordered_map>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("unordered_map<key, value>");
  /*
  * Holds hash table of <key, value> pairs in the native heap.
  * See unordered_set notes for discussion of hash tables.
  *
  * Like all the other STL containers std::unordered_map<key, value>
  * implements copy construction, move construction, copy assignment
  * move assignment, and destruction.
  *
  * Traits: key_type, value_type, iterator, ...
  */
  using UMapIntStr = std::unordered_map<int, std::string>;
  UMapIntStr umapIntStr{ { 5, "five" }, { 2, "two" }, { 7, "seven" } };
  std::cout << show(umapIntStr);

  int key = 4;
  std::string value = "for";
  umapIntStr[key] = value;   // inserts key and value pair
  std::cout << "\n  inserted " << showItem(*umapIntStr.find(4));
  std::cout << show(umapIntStr);

  value = "four";
  umapIntStr[key] = value;  // changes value
  std::cout << "\n  changed value: " << showItem(*umapIntStr.find(key));
  std::cout << show(umapIntStr);

  auto item = std::make_pair(key, "fore");
  auto result = umapIntStr.insert(item);  // fails - won't accept item with existing key
  std::cout << "\n  attempted to insert " << showItem(item);
  if (result.second)
    std::cout << show(umapIntStr);
  else
    std::cout << "\n  insert of " << showItem(item) << " failed";

  item = std::make_pair(9, "nine");
  std::cout << "\n  attempting to insert " << showItem(item);
  result = umapIntStr.insert(item);
  if (result.second)
    std::cout << show(umapIntStr);
  else
    std::cout << "\n  insert of " << showItem(*result.first) << " failed";

  std::cout << "\n  attempting to remove item with key = " << key;
  int numRemoved = umapIntStr.erase(key);
  std::cout << "\n  removed " << numRemoved << " items";
  std::cout << show(umapIntStr);

  std::cout << "\n  attempting to remove item with key = " << key;
  numRemoved = umapIntStr.erase(key);
  std::cout << "\n  removed " << numRemoved << " items";

  value = "seven";
  std::cout << "\n  removing all items with value = " << value;
  UMapIntStr::iterator pos;
  for (pos = begin(umapIntStr); pos != end(umapIntStr); ++pos)
  {
    if (pos->second == value)
      pos = umapIntStr.erase(pos);
  }
  std::cout << show(umapIntStr);
  std::cout << std::endl;

  std::cout << "\n  demonstrating hash<double>:";
  std::unordered_map<double, int> umapDblInt{ { 1.0, 1 }, { 3.1415927, 2 }, { 1.5e-4, 3 }, { -1.0 / 3.0, 4 } };
  std::cout << show(umapDblInt);

  std::cout << "\n  demonstrating hash<std::string>:";
  std::unordered_map<std::string, int> umapStrInt{ { "one", 1 }, { "two", 2 }, { "three", 3 }, { "four", 4 } };
  std::cout << show(umapStrInt);

  std::cout << "\n\n";
}