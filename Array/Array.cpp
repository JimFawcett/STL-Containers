///////////////////////////////////////////////////////////////
// Array.cpp - Demonstrate STL std::array<T>                 //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include <array>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("array<string>");
  /*
  * Holds a fixed allocation of contiguous memory like native arrays.
  * The array class is indexable and implements size().
  *
  * Traits: value_type, iterator, ...
  */
  std::array<std::string, 3> arrStr = { "first", "second", "third" };
  std::cout << show(arrStr);

  std::cout << "\n  array size = " << arrStr.size();
  std::cout << ", first element = " << parenWrap(arrStr[0]);       // no range check
  std::cout << ", second element = " << parenWrap(arrStr.at(1));   // throws if out of range
  
  std::cout << "\n\n";
}
