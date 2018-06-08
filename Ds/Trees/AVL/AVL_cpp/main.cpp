#include "AVLBST.h"

int main(void)
{
    AVLtree<int> t;

    cout << "Inserting integer values 1 to 10" << endl;
    for (int i = 1; i <= 10; ++i)
        t.insert(i);

    cout << "Printing balance: ";
    t.printBalance();
}
