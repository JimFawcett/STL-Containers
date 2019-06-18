/////////////////////////////////////////////////////////////////
// Utilities.cpp - utility functions for STL container demos   //
//                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014   //
/////////////////////////////////////////////////////////////////

#include "Utilities.h"
#include <iostream>
#include <string>

int main()
{
  std::cout << title("Demonstrating Utiltites", '=', true);
  std::string str = "this is a string";
  std::cout << title("Demonstrating show horizontal");
  std::cout << show(str);
  std::cout << title("Demonstrating show vertical");
  std::cout << show(str, true, vertical);
  std::cout << title("Demonstrating parenWrap");
  std::cout << "\n  " << parenWrap(str);

  std::cout << "\n\n";
}