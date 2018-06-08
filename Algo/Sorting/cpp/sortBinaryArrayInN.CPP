#include <bits/stdc++.h>
using namespace std;

/*
    YOU CAN COUNT ZEROES AND ONES OR..
*/

// Function to sort binary array in linear time
int Partition(int A[], int n)
{
    int pivot = 1;
    int j = 0;

    // each time we encounter a 0, j is incremented and
    // 0 is placed before the pivot
    for (int i = 0; i < n; i++)
    {
        if (A[i] < pivot)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
}

// main function
int main()
{
    int A[] = { 1, 0, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(A)/sizeof(A[0]);

    Partition(A, n);

    // print the rearranged array
    for (int i = 0 ; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
