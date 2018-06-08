#include <iostream>

using namespace std;

void Merge(int* arr, int* aux, int left, int mid, int right)
{
	for(int i = left; i <= right; i++)
		aux[i] = arr[i];
		
	int li = left;
	int ri = mid;
	int k = left;
		
	while(li < mid && ri <= right){
		if(aux[li] < aux[ri])
			arr[k++] = aux[li++];
		else
			arr[k++] = aux[ri++];
	}
	
	while(li < mid){
		arr[k++] = aux[li++];
	}
	while(ri < right){
		arr[k++] = aux[ri++];
	}
}

void MergeSort(int* arr, int* aux, int left, int right)
{
	
	if(left >= right)
		return;
	int mid = (right+left)/2;
	
	MergeSort(arr, aux, left, mid);
	MergeSort(arr, aux, mid+1, right);
	
	Merge(arr, aux, left, mid+1, right);
}

void MergeSort(int* arr, int len)
{
	int* aux = new int[len];
	
	MergeSort(arr, aux , 0, len-1);
}


void BubbleSort(int *arr, int len)
{
	
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j-1]); 
			}
		}
	}
	
	
}




int main()
{
	int arr[10] = {5,1654,656,8,6,1,64,6,9,6};
	
	BubbleSort(arr, 10);
	
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	
}
