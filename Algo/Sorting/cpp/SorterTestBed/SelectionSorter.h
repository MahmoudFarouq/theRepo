#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

#include "Sorter.h"

class SelectionSorter : public Sorter
{
    public:
        SelectionSorter();
        virtual ~SelectionSorter();
        void Sort(int arr[], int sz);
    protected:

    private:
};

#endif // SELECTIONSORTER_H
