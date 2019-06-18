///////////////////////////////////////////////////////////////
// Map.cpp - demonstrating STL std::map<K,V> container       //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include <map>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("map<key, value>");
  /*
  * Implements ordered collection with each element stored
  * independently in the native heap.  Implemented with a
  * balanced binary tree so insertion, retrieval and removal
  * are log n time.
  *
  * Traits: key_type, value_type, iterator, ...
  */
  using MapIntStr = std::map<int, std::string>;
  MapIntStr mapIntStr { { 5, "five" }, { 2, "two" }, { 7, "seven" } };
  std::cout << show(mapIntStr);

  int key = 4;
  std::string value = "for";
  mapIntStr[key] = value;   // inserts key and value pair
  std::cout << "\n  inserted " << showItem(*mapIntStr.find(4));
  std::cout << show(mapIntStr);

  value = "four";
  mapIntStr[key] = value;  // changes value
  std::cout << "\n  changed value: " << showItem(*mapIntStr.find(key));
  std::cout << show(mapIntStr);

  auto item = std::make_pair(key, "fore");
  auto result = mapIntStr.insert(item);  // fails - won't accept item with existing key
  std::cout << "\n  attempted to insert " << showItem(item);
  if (result.second)
    std::cout << show(mapIntStr);
  else
    std::cout << "\n  insert of " << showItem(item) << " failed";

  item = std::make_pair(9, "nine");
  std::cout << "\n  attempting to insert " << showItem(item);
  result = mapIntStr.insert(item);
  if (result.second)
    std::cout << show(mapIntStr);
  else
    std::cout << "\n  insert of " << showItem(*result.first) << " failed";

  std::cout << "\n  attempting to remove item with key = " << key;
  int numRemoved = mapIntStr.erase(key);
  std::cout << "\n  removed " << numRemoved << " items";
  std::cout << show(mapIntStr);

  std::cout << "\n  attempting to remove item with key = " << key;
  numRemoved = mapIntStr.erase(key);
  std::cout << "\n  removed " << numRemoved << " items";

  value = "seven";
  std::cout << "\n  removing all items with value = " << value;
  MapIntStr::iterator pos;
  for (pos = begin(mapIntStr); pos != end(mapIntStr); ++pos)
  {
    if (pos->second == value)
      pos = mapIntStr.erase(pos);
  }
  std::cout << show(mapIntStr);

  std::cout << "\n\n";
}