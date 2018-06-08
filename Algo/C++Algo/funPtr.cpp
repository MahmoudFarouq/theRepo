#include <set>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

class Node
{
public:
   Node(const string& name):myName(name){}

   bool operator<(const Node& other) const
   {
      return myName < other.myName;
   }

   friend ostream& operator<<(ostream& os, const Node& node)
   {
      os << node.myName;
      return os;
   }

   string name() const { return myName; }

private:
   string myName;
};
bool compareNode(const Node& lhs, const Node& rhs)
{
   return lhs < rhs;
}

typedef bool(*CompareFunc)(const Node&,const Node&);

int f(int x, int y)
{
    cout << x*y << endl;
}
typedef int (*fun)(int x, int y);

int F(fun s)
{
    s(5, 5);
}


int main()
{
    F(f);

   set<Node, CompareFunc> nodeSet(compareNode);

   nodeSet.insert(Node("node 1"));
   nodeSet.insert(Node("node 3"));
   nodeSet.insert(Node("node 2"));

   copy(nodeSet.begin(), nodeSet.end(), ostream_iterator<Node>(cout, "\n"));
}
