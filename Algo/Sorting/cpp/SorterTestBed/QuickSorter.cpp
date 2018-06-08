#include "QuickSorter.h"

QuickSorter::QuickSorter()
{
    //ctor
}

QuickSorter::~QuickSorter()
{
    //dtor
}
void QuickSorter::Sort(int arr[], int len)
{
    QuickSort(arr, 0, len-1);
}
void QuickSorter::QuickSort(int arr[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = Partition (arr, lo, hi);
    QuickSort (arr, lo, j-1);
    QuickSort (arr, j+1, hi);
}
int QuickSorter::Partition(int arr[], int lo, int hi)
{
    int i = lo;
    int j = hi+1;
    int temp;
    while(true)
    {
        while (arr [++i] < arr [lo])
            if (i >= hi)
                break;
        while (arr [lo] < arr [--j])
            if (j <= lo)
                break;
        if (i >= j)
            break;
        temp = arr [i];
        arr [i] = arr [j];
        arr [j] = temp;
    }
    temp = arr [lo];
    arr [lo] = arr [j];
    arr [j] = temp;
    return j;
}
