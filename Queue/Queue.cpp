///////////////////////////////////////////////////////////////////
// Queue.cpp - demonstrating STL std::qeque<T> container adapter //
//                                                               //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014     //
///////////////////////////////////////////////////////////////////

#include <queue>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("queue<T>");
  /*
  * By default std::queue is a wrapper around std::deque.
  * This means that operations on either end are constant time.
  * Queus are FIFO structures and so only provide access to the ends.
  *
  * Traits: value-type, iterator, ...
  */
  std::queue<double> qDbl;  // can't initialize
  double items[] = { -1.0, -0.5, 2.0, 1.0, -0.5, 3.0 };
  for (double item : items)
  {
    std::cout << "\n  pushing " << item;
    qDbl.push(item);
  }
  std::cout << "\n  size = " << qDbl.size() << std::endl;

  do
  {
    std::cout << "\n  popping " << qDbl.front();
    qDbl.pop();
  } while (qDbl.size() > 0);
  std::cout << "\n  size = " << qDbl.size();

  std::cout << "\n\n";
}
