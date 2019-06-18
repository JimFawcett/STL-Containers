///////////////////////////////////////////////////////////////////
// Stack.cpp - demonstrating STL std::qeque<T> container adapter //
//                                                               //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014     //
///////////////////////////////////////////////////////////////////

#include <stack>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("stack<T>");
  /*
  * By default std::stack is a wrapper around std::deque.
  * This means that operations on top are constant time.
  * Stacks are LIFO structures and so only provide access to the top.
  *
  * Traits: value-type, iterator, ...
  */
  std::stack<double> stkDbl;  // can't initialize
  double items[] = { -1.0, -0.5, 2.0, 1.0, -0.5, 3.0 };
  for (double item : items)
  {
    std::cout << "\n  pushing " << item;
    stkDbl.push(item);
  }
  std::cout << "\n  size = " << stkDbl.size() << std::endl;

  do
  {
    std::cout << "\n  popping " << stkDbl.top();
    stkDbl.pop();
  } while (stkDbl.size() > 0);
  std::cout << "\n  size = " << stkDbl.size();

  std::cout << "\n\n";
}
