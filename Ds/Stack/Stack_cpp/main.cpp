#include <iostream>
#include <Stack.h>
using namespace std;


int main()
{
    Stack<int> *s = new Stack<int>();

    s->Pop();
    for(int i = 0; i < 20; i++)
        s->Push(i);


    for(int i = 0; i < 10; i++)
        s->Pop();

    cout << s->Top() << endl;
    s->Print();
}



