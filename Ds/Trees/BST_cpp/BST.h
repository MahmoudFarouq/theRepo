#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template<class Key, class Value>
class BST
{
    typedef int (*Comparer)(Key first, Key second);

    class Node{
    public:
        Node(Key k, Value v){key = k; value = v;}
        Key key;
        Value value;
        Node* left=0;
        Node* right=0;
    };

    public:
        BST(Comparer com){
            root = NULL;
            Compare = com;
        }

        void Put(Key k, Value v){
            Node* parent = 0;
            Node* temp = root;
            if(root == NULL){
                root = new Node(k, v);
                return;
            }
            while(temp != NULL)
            {
                int com = Compare(temp->key, k);
                if(com == 0){
                    temp->value = v;
                    return;
                }
                else if(com > 0){
                    parent = temp;
                    temp = temp->left;
                }
                else{
                    parent = temp;
                    temp = temp->right;
                }
            }
            if(Compare(parent->key, k) > 0)
            {
                parent->left = new Node(k, v);
            }
            else
                parent->right = new Node(k, v);
            return;
        }

        Value Get(Key k){
			Node* temp = root;
			while(temp != NULL)
			{
				int cmp = Compare(temp->key, k);
				if(cmp == 0)
					return temp->value;
				else if(cmp > 0)
					temp = temp->left;
				else
					temp = temp->right;
			}
			return NULL;
		}

        bool Delete(Key k){
			Node* parent;
			Node* temp = root;
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
			if(temp == NULL) return false;
			int cmp = Compare(parent->key, temp->key);
			if(temp->left == NULL && temp->right == NULL)
			{
				if(cmp < 0)
					parent->right = NULL;
				else if(cmp > 0)
					parent->left = NULL;
				return true;
			}
			if(temp->right == NULL)
			{
				if(cmp < 0)
					parent->right = temp->left;
				else if(cmp > 0)
					parent->left = temp->left;
				return true;
			}
			if(temp->left == NULL)
			{
				if(cmp < 0)
					parent->right = temp->right;
				else if(cmp > 0)
					parent->left = temp->right;
				return true;
			}

			Node* temp2 = Min(temp->right);
			temp->key = temp2->key;
			temp->value = temp2->value;
			DeleteMin(temp->right);
			return true;
		}

        bool Contains(Key k){
			Node* temp = root;
			while(temp != NULL)
			{
				int cmp = Compare(temp->key, k);
				if(cmp == 0)
					return true;
				else if(cmp > 0)
					temp = temp->left;
				else
					temp = temp->right;
			}
			return false;
		}

        bool IsEmpty(){
			return (root == NULL);
		}

        Node* Min(){
			return Min(root);
		}
        Node* Min(Node* r){
			Node* temp = r;
			while(temp->left != NULL)
				temp = temp->left;
			return temp;
		}

        Node* Max(){
			return Max(root);
		}
        Node* Max(Node* r){
			Node* temp = r;
			while(temp->right != NULL)
				temp = temp->right;
			return temp;
		}

        Key Floor(Key k);
        Key Ceiling(Key k);

        void DeleteMax(){
			DeleteMax(root);
		}
        void DeleteMax(Node* n){
			Node* parent = 0;
			while(n->right != NULL){
				parent = n;
				n = n->right;
			}
			if(n->left != NULL)
			{
				parent->right = n->left;
			}
			else{
				parent->right = NULL;
			}
			delete n;
		}

        void DeleteMin(){
			DeleteMin(root);
		}
        void DeleteMin(Node* n){
			Node* parent = 0;
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

        void Print_DepthFirst(){
            Print_DepthFirst(root);
        }
        void Print_DepthFirst(Node* r){
            if(r == 0)
                return;
            Print_DepthFirst(r->left);
            cout << r->key << " -> " << r->value << endl;
            Print_DepthFirst(r->right);
        }

        void Print_BreadthFirst();

        void DeleteAll(Node* r){
            if(r == 0)
                return;
            DeleteAll(r->left);
            DeleteAll(r->right);
            delete r;
        }

        virtual ~BST(){
            DeleteAll(root);
        }

    protected:

    private:
        Node* root;
        Comparer Compare;
};

#endif // BST_H
