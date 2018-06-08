#ifndef STACK_H9
#define STACK_H
#include <iostream>
using namespace std;
template<class T>
class Stack
{
    struct Node
    {
        Node(T v, Node* nxt){value = v; next = nxt;}
        T value;
        Node* next;
    };
    public:
        Stack();
        Stack(T value, int intial_size);
        T& Top();
        void Pop();
        void Push(T value);
        int Size();
        void Print();
        virtual ~Stack();
    private:
        Node* tail;
        int sz;
};

#endif // STACK_H
