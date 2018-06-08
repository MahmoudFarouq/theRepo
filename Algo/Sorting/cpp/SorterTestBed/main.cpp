#include "SelectionSorter.h"
#include "QuickSorter.h"
#include "TestBed.h"

int main()
{
    srand(time(0));

    TestBed tb;
    QuickSorter qs;
    SelectionSorter ss;

    int type = 0;
    int mini = 20;
    int maxi = 1000;
    int min_len = 1000;
    int max_len = 2000;
    int step = 10;
    int sets_num = 10;

    cout << tb.RunExperient(qs, type, mini, maxi, min_len, max_len, step, sets_num) << endl;
    return 0;
}
