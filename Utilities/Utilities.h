///////////////////////////////////////////////////////////////
// Utilities.h - utility functions for STL container demos   //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include <string>
#include <sstream>

/*----< show item >------------------------------------------*/

template <typename T>
std::string showItem(const T& item)
{
  std::ostringstream out;
  out << item;
  return out.str();
}
/*----< show pair as item >----------------------------------*/

template <typename K, typename V>
std::string showItem(const std::pair<K, V>& pr)
{
  std::ostringstream out;
  out << "{" << (pr.first) << ", " << (pr.second) << "}";
  return out.str();
}

/*----< display contents of STL container >------------------*/

enum alignment { horizontal, vertical };

template <typename Cont>
std::string show(Cont& cont, bool endNewLine = false, alignment al = alignment::horizontal)
{
  std::ostringstream out;
  out << "\n  ";
  bool first = true;
  for (auto item : cont)
  {
    if (first)
    {
      out << showItem(item);
      first = false;
    }
    else if (al == horizontal)
      out << ", " << showItem(item);
    else
      out << "\n  " << showItem(item);
  }
  if (endNewLine)
    out << std::endl;
  return out.str();
}
/*----< display title with underline >-----------------------*/

inline std::string title(const std::string& t, char underline = '-', bool endNewLine = false)
{
  std::ostringstream out;
  out << "\n  " << t << "\n ";
  out << std::string(t.size() + 2, underline);
  if (endNewLine)
    out << std::endl;
  return out.str();
}
/*----< wrap string in parentheses >-------------------------*/

inline std::string parenWrap(const std::string& s)
{
  std::ostringstream out;
  out << "\"" << s << "\"";
  return out.str();
}
