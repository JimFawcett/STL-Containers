///////////////////////////////////////////////////////////////
// Deque.cpp - demonstrating STL std::deque<T> container     //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////


#include <deque>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("deque<double>");
  /*
  * Has two or more blocks of contiguous memory.
  * first fills from the back toward the front.
  * last fills from the front toward the back.
  * This means that operations on either end are constant time.
  *
  * Traits: value-type, iterator, ...
  */
  std::deque<double> deqDbl{ -1.0, 3.1415927, 1.5e-3 };
  std::cout << show(deqDbl);
   
  /* operations on both ends are efficient */
  double d{ 1.0 / 3.0 };
  std::cout << "\n  pushing " << d << " into front and back:";
  deqDbl.push_front(d);
  deqDbl.push_back(d);
  std::cout << show(deqDbl);
  std::cout << "\n  popping from front and back:";
  deqDbl.pop_front();
  deqDbl.pop_back();
  std::cout << show(deqDbl);
  
  /* deques are indexable */
  std::cout << "\n  second element = " << deqDbl[1] << std::endl;

  /*
  * Note: deque doesn't provide capacity()
  */
  std::cout << "\n\n";
}