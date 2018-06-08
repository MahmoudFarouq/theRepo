#include "Queue.h"

template<class T>
Queue<T>::Queue()
{
    tail = head = NULL;
    sz = 0;
}

template<class T>
Queue<T>::Queue(T value, int intial_size)
{
    sz = intial_size;
    if(intial_size > 0)
    {
        Node* temp = new Node(value, NULL);
        tail = head = temp;
        intial_size--;
    }else{
        tail = head = NULL;
    }
    while(intial_size > 0)
    {
        Node* temp = new Node(value, NULL);
        tail->prev = temp;
        tail = temp;
        intial_size--;
    }
}

template<class T>
T* Queue<T>::Front()
{
    try{
        if(head != NULL)
            return &(head->value);
        throw(0);
    catch(...){
        cout << "EmptyQueue" << endl;
    }
}

template<class T>
void Queue<T>::Pop()
{
    sz--;
    if(head == NULL)
        return;
    Node* temp = head;
    head = head->prev;
    delete temp;
}
template<class T>
void Queue<T>::Push(T value)
{
    Node* temp = new Node(value, NULL);
    if(tail == NULL)
    {
        tail = head = temp;
        sz++;
        return;
    }
    tail->prev = temp;
    tail = temp;
    sz++;
}
template<class T>
int Queue<T>::Size()
{
    return sz;
}

template<class T>
void Queue<T>::Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
}


template<class T>
Queue<T>::~Queue()
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp = head;
        head = head->prev;
        delete temp;
    }
}

template class Queue<int>;

