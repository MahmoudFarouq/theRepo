#include "AVLBST.h"

template <class T>
void AVLtree<T>::rebalance(AVLnode<T> *n, T k)
{
    if(n == NULL)
        return;
    setBalance(n);
    if (n->balance == -2)
    {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2)
    {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }
    else if(k > n->key)
        return rebalance(n->right, k);
    else if(k < n->key)
        return rebalance(n->left, k);
    else
        return;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateLeft(AVLnode<T> *n)
{
    AVLnode<T>* temp = n;
    n = n->right;
    temp->right = n->left;
    n->left = temp;
    return n;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateRight(AVLnode<T> *n)
{
    AVLnode<T>* temp = n;
    n = n->left;
    temp->left = n->right;
    n->right = temp;
    return n;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateLeftThenRight(AVLnode<T> *n)
{
    n->left = rotateLeft(n->left);
    n = rotateRight(n);
    return n;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateRightThenLeft(AVLnode<T> *n)
{
    n->right = rotateRight(n->right);
    n = rotateLeft(n);
    return n;
}

template <class T>
int AVLtree<T>::height(AVLnode<T> *n)
{
    if (n == NULL)
        return -1;
    return 1 + max(height(n->left), height(n->right));
}

template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *n)
{
    n->balance = height(n->right) - height(n->left);
}

template <class T>
void AVLtree<T>::printBalance(AVLnode<T> *n)
{
    if (n != NULL)
    {
        printBalance(n->left);
        cout << n->balance << " ";
        printBalance(n->right);
    }
}

template <class T>
AVLtree<T>::AVLtree(void) : root(NULL) {}

template <class T>
AVLtree<T>::~AVLtree(void)
{
    delete root;
}

template <class T>
bool AVLtree<T>::insert(T key)
{
    root = Insert(root, key);
    rebalance(root, key);
}

template <class T>
AVLnode<T>* AVLtree<T>::Insert(AVLnode<T>* rt, T key)
{

    if (rt == NULL){
        return new AVLnode<T>(key);
    }
    if(rt->key == key)
        return rt;
    if(rt->key < key)
        rt->right = Insert(rt->right, key);
    else if(rt->key > key)
        rt->left = Insert(rt->left, key);

    return rt;
}

template <class T>
int AVLtree<T>::Compare(T t1, T t2){
    int cmp;
    if(t1 > t2) cmp = 1;
    if(t1 < t2) cmp = -1;
    else cmp = 0;
    return cmp;
}


template <class T>
void AVLtree<T>::deleteKey(const T k){
    AVLnode<T>* parent;
    AVLnode<T>* temp = root;
    while(temp != NULL)
    {
        int cmp = Compare(temp->key, k);
        if(cmp == 0)
            break;
        else if(cmp > 0){
            parent = temp;
            temp = temp->left;
        }
        else{
            parent = temp;
            temp = temp->right;
        }
    }
    if(temp == NULL) return;
    int cmp = Compare(parent->key, temp->key);
    if(temp->left == NULL && temp->right == NULL)
    {
        if(cmp < 0)
            parent->right = NULL;
        else if(cmp > 0)
            parent->left = NULL;
        return;
    }
    if(temp->right == NULL)
    {
        if(cmp < 0)
            parent->right = temp->left;
        else if(cmp > 0)
            parent->left = temp->left;
        return;
    }
    if(temp->left == NULL)
    {
        if(cmp < 0)
            parent->right = temp->right;
        else if(cmp > 0)
            parent->left = temp->right;
        return;
    }

    AVLnode<T>* temp2 = Min(temp->right);
    temp->key = temp2->key;
    DeleteMin(temp->right);
    return;
}


template <class T>
void AVLtree<T>::printBalance()
{
    printBalance(root);
    cout << endl;
}

template <class T>
void AVLtree<T>::Print_PostOrder()
{
    Print_PostOrder(root);
}
template <class T>
void AVLtree<T>::Print_PostOrder(AVLnode<T>* r)
{
    if(r == 0)
        return;
    Print_PostOrder(r->left);
    Print_PostOrder(r->right);
    cout << r->key << endl;
}

template <class T>
void AVLtree<T>::Print_PreOrder()
{
    Print_PreOrder(root);
}
template <class T>
void AVLtree<T>::Print_PreOrder(AVLnode<T>* r)
{
    if(r == 0)
        return;
    cout << r->key << endl;
    Print_PreOrder(r->left);
    Print_PreOrder(r->right);
}

template <class T>
void AVLtree<T>::Print_InOrder()
{
    Print_InOrder(root);
}
template <class T>
void AVLtree<T>::Print_InOrder(AVLnode<T>* r)
{
    if(r == 0)
        return;
    Print_InOrder(r->left);
    cout << r->key << endl;
    Print_InOrder(r->right);
}

template class AVLtree<int>;

