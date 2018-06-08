#include "List.h"

template<class T>
List<T>::List()
{
    head = tail = NULL;
    sz = 0;
}

template<class T>
List<T>::List(T value, int initial_size)
{
    sz = initial_size;
    head = new Node(value, NULL, NULL);
    tail = head;
    while(initial_size-- > 0)
    {
        --value;
        Node* temp = new Node(value, tail, NULL);
        tail->next = temp;
        tail = temp;
    }
}

template<class T>
int List<T>::Size(){return sz;}

template<class T>
void List<T>::Insert(T value, Iterator& position)
{
    if(position.getNode() == head)
    {
        if(head == NULL)
        {
            Node* temp = new Node(value, NULL, NULL);
            head = temp;
            tail = temp;
        }
        else
        {
            Node* temp = new Node(value, NULL, head);
            head->prev = temp;
            head = temp;
        }
        position.setNode(head);
    }
    else if (position.getNode() == tail)
    {
        Node* temp = new Node(value, tail->prev, tail);
        tail->prev = temp;
        temp->prev->next = temp;
        position.setNode(tail->prev);
    }
    else{
        Node* temp = new Node(value, position.getNode()->prev, position.getNode());
        temp->prev->next = temp;
        temp->next->prev = temp;
        position.setNode(temp->prev);
    }
    sz++;
}

template<class T>
typename List<T>::Iterator& List<T>::Erase(Iterator& position)
{
    if(position.getNode()->next != NULL){
        position.getNode()->next->prev = position.getNode()->prev;
    }else{
        tail = tail->prev;
    }
    if(position.getNode()->prev != NULL){
        position.getNode()->prev->next = position.getNode()->next;
    }else{
        head = head->next;
    }
    Node* temp = position.getNode();
    position++;
    if(position.getNode() == tail->next) throw("OutOfBoundary");
    delete temp;
    sz--;
    return position;
}

template<class T>
List<T>& List<T>::operator=(List<T>& another_list)
{

    Clear();
    List<T>::Iterator it = another_list.End(), it2 = Begin();
    while(it != another_list.Begin())
    {
        Insert(*it, it2);
        it--;
    }
    Insert(*it, it2);
    return *this;
}

template<class T>
typename List<T>::Iterator& List<T>::Begin()
{
    Iterator it;
    it.setNode(head);
    return it;
}
template<class T>
typename List<T>::Iterator& List<T>::End()
{
    Iterator it;
    it.setNode(tail);
    //it.setNode(tail->next);
    return it;
}

template<class T>
List<T>::~List()
{
    Clear();
}

template<class T>
void List<T>::Clear()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = head;
    sz = 0;
}
template<class T>
void List<T>::Print()
{
    Iterator it = Begin();
    while(it != End())
    {
        cout << *it << " ";
        it++;
    }
    cout << *it << endl;
}


template class List<int>;
