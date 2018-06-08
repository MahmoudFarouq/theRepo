#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template<class T>
class List
{
    struct Node
    {
        Node(T d, Node* p, Node* n){data = d; next = n;prev = p;}
        T data;
        Node* next = 0;
        Node* prev = 0;
    };
    public:

        class Iterator
        {
        public:
            Iterator(){curNode = NULL;}
            void operator++(int x)
            {
                try{
                    if(curNode != NULL)
                        curNode = curNode->next;
                    else{
                    throw("NullException");}
                }catch(const char *x){cout << x << endl;}
            }
            void operator--(int x)
            {
                try{
                    if(curNode != NULL)
                        curNode = curNode->prev;
                    else{
                    throw("NullException");}
                }catch(const char *x){cout << x << endl;}
            }
            T& operator*()
            {
                try{
                    if(curNode != NULL)
                        return curNode->data;
                    throw("NullException");
                }catch(const char *x){cout << x << endl;}
            }
            bool operator==(const Iterator& that)
            {
                return (curNode == that.curNode);
            }
            bool operator!=(const Iterator& that)
            {
                return (curNode != that.curNode);
            }
            Node* getNode(){return curNode;}
            void setNode(Node* other){curNode = other;}
            void operator=(const Iterator& that)
            {
                curNode = that.curNode;
            }
        private:
            Node* curNode = 0;
        };

        List();
        List(T value, int initial_size);
        int Size();
        void Insert(T value, Iterator& position);
        Iterator& Erase(Iterator& position);
        List<T>& operator=(List<T>& another_list);
        Iterator& Begin();
        Iterator& End();
        void Clear();
        void Print();

        virtual ~List();

    protected:

    private:
        Node* head = 0;
        Node* tail = 0;
        int sz;
};

#endif // LIST_H
