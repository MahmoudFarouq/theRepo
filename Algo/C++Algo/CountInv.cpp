// GROUP:   4
// ID:      20150239
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    mahmoud reda farouk

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long counter = 0;
long long Merge(long long* array, long long n){
	long long* aux = new long long[n];
	//memcpy(aux, array, n);
    for(long long i = 0; i < n; i++) {aux[i] = array[i];}

    long long leftIndex = 0;
    long long rightIndex= n/2;
    long long k = 0;

    while( leftIndex < n/2 && rightIndex < n )
    {
        if( aux[leftIndex] < aux[rightIndex]){
            array [k++] = aux [leftIndex++];
        }
        else{
            array[k++] = aux[rightIndex++];
            counter += (n/2 - leftIndex);
        }
    }
    while (leftIndex < n/2){
        array [k++] = aux [leftIndex++];
    }
    while (rightIndex < n){
        array[k++] = aux[rightIndex++];
    }
    return 0;
}
long long MergeSort(long long* a, long long n){
    if (n > 1) {
        int mid = n/2;
        MergeSort (a, mid);
        MergeSort (a+mid, n-mid);
        Merge (a, n);
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    long long n;
    while(cin >> n && n){
		long long* array = new long long[n];
        for(long long i = 0; i < n; i++)
            cin >> array[i];
        MergeSort(array, n);
        cout << counter << endl;
        counter = 0;
    }
    return 0;
}
