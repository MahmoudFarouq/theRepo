#include <iostream>
#include <Queue.h>
using namespace std;

int main()
{
    Queue<int> *q = new Queue<int>(5, 10);

    q->Pop();
    for(int i = 0; i < 20; i++)
        q->Push(i);


    for(int i = 0; i < 10; i++)
        q->Pop();

    if(q->Front() != 0)
        cout << *q->Front() << endl;

    q->Print();

    return 0;
}
