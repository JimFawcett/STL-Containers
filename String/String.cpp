/////////////////////////////////////////////////////////////////////
// String.cpp - demonstrating STL std::qeque<T> container adapter  //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014       //
/////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("std::string");
  /*
  * By default std::string contains UTF-8 characters in contiguous 
  * memory on the native heap, and strings are indexable.  That 
  * means that operations on either end are constant time, as are 
  * operations at a specified index.
  *
  * std::strings provide iterators, begin(), and end(), so the
  * usual STL operations work.
  *
  * Traits: value-type, iterator, ...
  */
  std::string vowels { 'a', 'e', 'i', 'o', 'u' };
  std::cout << show(vowels);

  std::string str = "this is a string";
  std::cout << show(str);

  char value = 's';
  std::vector<int> indices;
  for (size_t i = 0; i < str.size(); ++i)
  {
    if (str[i] == value)
      indices.push_back(i);
  }
  std::cout << "\n  string contains " << value << " at locations :";
  std::cout << show(indices);

  std::cout << "\n\n";
}