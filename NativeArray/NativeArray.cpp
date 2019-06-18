/////////////////////////////////////////////////////////////////////
// NativeArray.cpp - demonstrating native array as STL container   //
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
  std::cout << title("C++ native array");
  /*
  * Native arrays are indexable contiguous memory.  That means
  * that operations at a specified index are constant time.
  *
  * Native pointers are iterators for native arrays.  The global
  * functions std::begin(), and std::end() are overloaded for
  * navtive arrays, so the usual STL operations work.
  *
  * Traits: value-type, iterator, ...
  */
  std::cout << "\n  initialized from char sequence";
  char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
  std::cout << show(vowels) << std::endl;

  std::cout << "\n  initialized from a string";
  char str[] = "this is a string";
  std::cout << show(str) << std::endl;

  std::wcout << "\n  initialized from an int sequence";
  int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::cout << show(digits) << std::endl;

  int oldValue = 2;
  int newValue = -1;
  std::cout << "\n  overwriting " << oldValue << " with " << newValue;
  int* posPtr = std::find(std::begin(digits), std::end(digits), oldValue);
  int index = std::distance(std::begin(digits), posPtr);
  digits[index] = newValue;
  std::cout << show(digits);

  std::cout << "\n\n";
}