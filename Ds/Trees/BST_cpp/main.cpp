#include "BST.h"
#include <ctime>
#include <cstdlib>

int compare(int x, int y)
{
    if(x == y)return 0;
    if(x > y) return 1;
    return -1;
}

int main()
{
    srand(time(0));
    BST<int, int> *bst = new BST<int, int>(compare);

    for(int i = 0; i < 20; i++)
    {
		int temp = rand()%100+1;
        bst->Put(temp, temp);
    }
    bst->Put(1000, 1000);
	bst->Put(555, 555);
	bst->Put(777, 777);
	bst->Print_DepthFirst();

    bst->Delete(1000);
    cout <<"555's value: " << bst->Get(555) << endl;
    cout <<"is it contains 777: " << bst->Contains(777) << endl;
    cout <<"MinValue: " << bst->Min()->value << endl;
    cout <<"MaxValue: " << bst->Max()->value << endl;

	bst->DeleteMax();
	bst->DeleteMin();

	bst->Print_DepthFirst();


    return 0;
}
