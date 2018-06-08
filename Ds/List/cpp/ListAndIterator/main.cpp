#include <iostream>
#include <List.h>
#include <exception>
using namespace std;

int main()
{
    List<int> ls;
    List<int>::Iterator it = ls.Begin();

    ls.Insert(5, it);
    ls.Insert(10, it);
    ls.Insert(15, it);
    it++;
    ls.Insert(20, it);

    *it = 5555;

    cout << "the complete list: ";
    ls.Print();

    it = ls.Begin();
    cout << "Before Erase: " << *it << endl;
    it = ls.Erase(it);
    cout << "After Erase: " << *it << endl;
    it = ls.Begin();

    cout << "the complete list: ";
    ls.Print();

    cout << "Size: " << ls.Size() << endl;

    List<int> ls2;
    ls2 = ls;

    it = ls2.Begin();
    cout << "the complete list After Copy: ";
    ls2.Print();



    return 0;
}
