#include <iostream>
#include <string.h>
#include <cstdlib>

void merge(int array[], int left, int mid, int right);
void mergeSort(int array[], int left, int right);

void bubble_sort(int array[], int len, char x);

void selection_sort(int array[], int len, char x);

void insertion_sort(int array[], int len, char x);

void shell_sort(int array[], int len);

int find_max(int array[], int len);
void counting_sort(int array[], int len);

void knuthShuffle(int array[], int len);

using namespace std;
int main()
{
	int array[] = {31,321,54,231,45,132,431,64,315,3646,1358,65461};
	mergeSort(array, 0, 11);
	for(int j = 0; j < 12; j++)
	{
		cout << array[j] << endl;
	}
}
void insertion_sort(int array[], int len, char x)
{
	int lastSortedIndex = 0;
	for(int i = 1; i < len; i++)
	{
		if(array[lastSortedIndex] > array[i] )
		{
			int toBeMoved = array[i];
			int index = lastSortedIndex;
			while(toBeMoved < array[index] )
			{
				array[index+1] = array[index];
				index--;
			}
			array[index+1] = toBeMoved;
		}
		lastSortedIndex++;
	}	
}
void selection_sort(int array[], int len, char x)
{
	for(int i = 0; i < len; i++)
	{
		int max_index=i, min_index=i, temp;
		for(int j = i; j < len; j++)
		{
				 if(array[j] > array[max_index]){max_index = j;}
			else if(array[j] < array[min_index]){min_index = j;}
		}
		int tempIndex = (x == 'i' ? min_index:max_index);
		temp = array[tempIndex];
		array[tempIndex] = array[i];
		array[i] = temp;
	}
}
void bubble_sort(int array[], int len, char x)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len-1-i; j++)
		{
			if((array[j] > array[j+1] && x == 'i') || (array[j] < array[j+1] && x == 'd'))
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
void shell_sort(int array[], int len)
{
	int h = 1;
	while(h < len/3) h = 3*h+1;
	while(h >= 1)
	{	
		for(int i = h; i < len; i++)
		{
			for(int j = i; j >= h; j -= h)
			{
				if(array[j] < array[j-h])
				{
					int temp = array[j];
					array[j] = array[j-h];
					array[j-h] = temp;
				}
			}
		}
		h = h/3;
	}
}
void counting_sort(int array[], int len)
{
	int newLen = find_max(array, len)+1;
	int *newArray = new int[newLen];
	
	for(int i = 0; i < newLen; i++) newArray[i] = 0;
	
	for(int i = 0; i < len; i++) ++newArray[array[i]];
	
	int tracer = 0;
	for(int i = 0; i < newLen; i++) 
	{
		if(newArray[i] != 0)
		{
			for(int j = 0; j < newArray[i]; j++)
			{
				array[tracer] = i;
				++tracer;
			}
		}
	}
}
int find_max(int array[], int len)
{
	int max = 0;
	for(int i = 0; i < len; i++)
	{
		max = (max > (array[i]) ? max:array[i]);
	}
	return max;
}
void mergeSort(int array[], int left, int right)
{
	if(left < right)
	{
		int mid = left + (right-left)/2;
		
		mergeSort(array, left, mid);
		mergeSort(array, mid+1, right);
		
		merge(array, left, mid, right);
	}
}
void merge(int array[], int left, int mid, int right)
{
	int lenL, lenR;
	lenL = mid-left+1;
	lenR = right - mid;
	
	int L[lenL], R[lenR];
	
	for(int i = 0; i < lenL; i++) {L[i] = array[left+i];}
	
	for(int i = 0; i < lenR; i++) {R[i] = array[mid+1+i];} 
	
	int leftIndex = 0; 
	int rightIndex= 0;
	int k = left;
	
	
	while( leftIndex < lenL && rightIndex < lenR )
	{
		if( L[leftIndex] <= R[rightIndex] )
		{
			array[k] = L[leftIndex];
			leftIndex++;
		}
		else
		{
			array[k] = R[rightIndex]; 
			rightIndex++; 
		}
		k++;
	}
	
	
	while (leftIndex < lenL)
	{
		array[k] = L[leftIndex];
		leftIndex++;
		k++;
	}
	while (rightIndex < lenR)
	{
		array[k] = R[rightIndex];
		rightIndex++;
		k++;
	}
}
void knuthShuffle(int array[], int len)
{
	for(int i = 1; i < len; i++)
	{
		int r = rand()%i;
		int temp = array[r];
		array[r] = array[i];
		array[i] = temp;
	}
}




















