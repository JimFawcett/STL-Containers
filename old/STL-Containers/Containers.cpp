// Containers.cpp

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <sstream>


#include <iostream>
#include "../Utilities/Utilities.h"

int main()
{
  std::cout << title("Demonstrate use of STL Containers", '=', true);

  /*---------------------------------------------------------*/
  std::cout << title("array<string>");
  /*
   * Holds a fixed allocation of contiguous memory like native arrays.
   * The array class is indexable and implements size().
   */
  std::array<std::string, 3> arrStr = { "first", "second", "third" };
  std::cout << show(arrStr);
  std::cout << "\n  array size = " << arrStr.size();
  std::cout << ", first element = " << parenWrap(arrStr[0]);       // no range check
  std::cout << ", second element = " << parenWrap(arrStr.at(1));   // throws if out of range
  std::cout << std::endl;

  /*---------------------------------------------------------*/
  std::cout << title("vector<string>");
  /*
   * Has a single block of contiguous memory which fills from the back.
   * So operations on the back are constant time while operations on 
   * the front are linear time.
   *
   * If you push_back or insert into a full vector (size == capacity)
   * a new block of memory twice as large as the former will be allocated
   * and elements copied before push_back or insert.
   */
  std::vector<std::string> vecStr{ "first", "second", "third" };
  std::cout << show(vecStr);
  std::cout << "\n  vector size = " << vecStr.size();
  std::cout << ", vector capacity = " << vecStr.capacity();
  std::cout << "\n  first element = " << vecStr.front() << ", last element = " << vecStr.back();
  std::cout << "\n  second element = " << vecStr[1];
  std::cout << "\n  removing last element: ";
  vecStr.pop_back();
  std::cout << show(vecStr);
  std::cout << "\n  removing first element: ";
  vecStr.erase(begin(vecStr));
  std::cout << show(vecStr);
  std::cout << "\n  vector size = " << vecStr.size();
  std::cout << ", vector capacity = " << vecStr.capacity() << std::endl;

  /*---------------------------------------------------------*/
  std::cout << title("deque<double>");
  /*
   * Has two or more blocks of contiguous memory.
   * first fills from the back toward the front.
   * last fills from the front toward the back.
   * This means that operations on either end are constant time.
   */
  std::deque<double> deqDbl{ -1.0, 3.1415927, 1.5e-3 };
  std::cout << show(deqDbl);
  /* operations on both ends are efficient */
  double d{ 1.0 / 3.0 };
  std::cout << "\n  pushing " << d << " into front and back:";
  deqDbl.push_front(d);
  deqDbl.push_back(d);
  std::cout << show(deqDbl);
  std::cout << "\n  pop-ing " << d << " from front and back:";
  deqDbl.pop_front();
  deqDbl.pop_back();
  std::cout << show(deqDbl);
  std::cout << "\n  second element = " << deqDbl[1] << std::endl;
  /*
   * Note: deque doesn't provide capacity()
   */

  /*---------------------------------------------------------*/
  std::cout << title("list<int>");
  /*
   * Implements doubly linked list with each element stored
   * independently in the native heap.  Operations on either
   * end are constant time while operations in the middle are
   * linear time.
   */
  std::list<int> lint{ 3, 2, 1, 0, -1, 0, 1 };
  std::cout << show(lint);

  std::cout << "\n\n";
}