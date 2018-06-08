#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
    tail = NULL;
    sz = 0;
}

template<class T>
Stack<T>::Stack(T value, int intial_size)
{
    sz = intial_size;
    tail = NULL;
    while(intial_size > 0)
    {
        Node* temp = new Node(value, tail);
        tail = temp;
        intial_size--;
    }
}

template<class T>
T& Stack<T>::Top()
{
    try{
        if(tail != NULL)
            return tail->value;
        throw(0);
    }catch(...){cout << "EmptyStack" << endl;}
}

template<class T>
void Stack<T>::Pop()
{
    sz--;
    if(tail == NULL)
        return;
    Node* temp = tail;
    tail = tail->next;
    delete temp;
}
template<class T>
void Stack<T>::Push(T value)
{
    Node* temp = new Node(value, tail);
    tail = temp;
    sz++;
}
template<class T>
int Stack<T>::Size()
{
    return sz;
}

template<class T>
void Stack<T>::Print()
{
    Node* temp = tail;
    while(temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}


template<class T>
Stack<T>::~Stack()
{
    Node* temp = tail;
    while(temp != NULL)
    {
        temp = tail;
        tail = tail->next;
        delete temp;
    }
}

template class Stack<int>;


