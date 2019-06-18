/////////////////////////////////////////////////////////////////////////
// ForwardList.cpp - demonstrating STL std::forward_list<T> container  //
//                                                                     //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014           //
/////////////////////////////////////////////////////////////////////////


#include <forward_list>
#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  /*---------------------------------------------------------*/
  std::cout << title("forward_list<int>");
  /*
  * Implements singly linked list with each element stored
  * independently in the native heap.  Operations on front are
  * constant time while operations elsewhere are linear time.
  *
  * Traits: value_type, iterator, ...
  */
  std::forward_list<int> lint{ 3, 2, 1, 0, -1, 0, 1 };
  std::cout << show(lint);

  /* operations on front are constant time */
  std::cout << "\n  pushing " << 3 << " onto front:";
  lint.push_front(3);
  std::cout << show(lint);
  std::cout << "\n  popping from front:";
  lint.pop_front();
  std::cout << show(lint);
  /* insertion is linear time */
  std::cout << "\n  inserting -15 after second element:";
  lint.insert_after(++begin(lint), -15);
  std::cout << show(lint) << std::endl;

  /* forward_lists can't be walked back to front */
  std::cout << "\n\n";

}