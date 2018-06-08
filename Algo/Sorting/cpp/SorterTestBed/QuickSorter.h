#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "Sorter.h"

class QuickSorter :  public Sorter
{
    public:
        QuickSorter();
        virtual ~QuickSorter();
        void Sort(int arr[], int len);
        void QuickSort(int arr[], int lo, int hi);
        int Partition(int arr[], int lo, int hi);

    protected:

    private:
};

#endif // QUICKSORTER_H
