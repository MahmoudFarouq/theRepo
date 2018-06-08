#include "SelectionSorter.h"

SelectionSorter::SelectionSorter()
{
    //ctor
}

SelectionSorter::~SelectionSorter()
{
    //dtor
}
void SelectionSorter::Sort(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		int min_index=i, temp;
		for(int j = i; j < len; j++)
		{
				 if(arr[j] < arr[min_index]){min_index = j;}
		}
		temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp;
	}
}
