// test

#include <map>
#include <string>

template <class K, class V, template <class K, class V> class Cont>
class Test
{
public:
  std::string show(Cont<K, V>& cont)
  {

  }
};

int main()
{
  //Test<int, double, std::map> t;
  //t.show(std::map<int,double>());
}