///////////////////////////////////////////////////////////////
// List.cpp - demonstrating STL std::list<T> container       //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////


#include <list>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("list<int>");
  /*
  * Implements doubly linked list with each element stored
  * independently in the native heap.  Operations on either
  * end are constant time while operations in the middle are
  * linear time.
  *
  * Traits: value_type, iterator, ...
  */
  std::list<int> lint{ 3, 2, 1, 0, -1, 0, 1 };
  std::cout << show(lint);

  /* operations on both ends are efficient */
  std::cout << "\n  pushing " << 3 << " into front and back:";
  lint.push_front(3);
  lint.push_back(3);
  std::cout << show(lint);
  std::cout << "\n  popping from front and back:";
  lint.pop_front();
  lint.pop_back();
  std::cout << show(lint);
  /* insertion is linear time */
  std::cout << "\n  inserting -15 after first element:";
  lint.insert(++begin(lint), -15);
  std::cout << show(lint) << std::endl;

  /* lists can be walked back to front as well as front to back */
  std::cout << "\n  walking list in reverse:\n  ";
  std::list<int>::reverse_iterator riter = lint.rbegin();
  while (riter != lint.rend())
    std::cout << *riter++ << " ";

  /* can splice two lists and can merge two ordered lists */
  std::list<int> mlist{ 1, 1, 1, 1 };
  std::cout << "\n  can splice two lists:";
  std::cout << show(mlist);
  mlist.splice(end(mlist), lint);  // elements moved so lint is now empty
  std::cout << show(mlist);
  lint.push_back(3);               // lint is still usable
  std::cout << show(lint);
  std::cout << "\n\n";

}