#ifndef AVLBST_H
#define AVLBST_H
#include <algorithm>
#include <iostream>
using namespace std;
/* AVL node */
template <class T>
class AVLnode
{
public:
    T key;
    int balance;
    AVLnode *left=0, *right=0;

    AVLnode(T k):key(k), balance(0){}
    ~AVLnode()
    {
        delete left;
        delete right;
    }
};

/* AVL tree */
template <class T>
class AVLtree
{
public:
    AVLtree();
    ~AVLtree();
    bool insert(T key);
    AVLnode<T>* Insert(AVLnode<T>* rt, T key);
    void deleteKey(const T key);
    void printBalance();

private:
    AVLnode<T> *root;
    AVLnode<T>* rotateLeft          ( AVLnode<T> *a );
    AVLnode<T>* rotateRight         ( AVLnode<T> *a );
    AVLnode<T>* rotateLeftThenRight ( AVLnode<T> *n );
    AVLnode<T>* rotateRightThenLeft ( AVLnode<T> *n );
    void rebalance                  ( AVLnode<T> *n, T k);
    int height                      ( AVLnode<T> *n );
    void setBalance                 ( AVLnode<T> *n );
    void printBalance               ( AVLnode<T> *n );
    void clearNode                  ( AVLnode<T> *n );
    int Compare(T t1, T t2);
    void Print_PostOrder();
    void Print_PostOrder(AVLnode<T>*);
    void Print_PreOrder();
    void Print_PreOrder(AVLnode<T>*);
    void Print_InOrder();
    void Print_InOrder(AVLnode<T>*);


    AVLnode<T>* Min(){
        return Min(root);
    }
    AVLnode<T>* Min(AVLnode<T>* r){
        AVLnode<T>* temp = r;
        while(temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    void DeleteMin(){
        DeleteMin(root);
    }
    void DeleteMin(AVLnode<T>* n){
        AVLnode<T>* parent = 0;
        while(n->left != NULL){
            parent = n;
            n = n->left;
        }
        if(n->right != NULL)
        {
            parent->left = n->right;
        }
        else{
            parent->left = NULL;
        }
        delete n;
    }
};

#endif // AVLBST_H
