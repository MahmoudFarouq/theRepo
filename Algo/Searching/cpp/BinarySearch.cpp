#include <iostream>
using namespace std;
int BinarySearch(int array[], int key, int len);
int LowerBound(int array[], int key, int len);
int UpperBound(int array[], int key, int len);
int main()
{
	int array[] = {1,2,3,4,4,4,4,4,4,5,6,7,8,9};
	
	cout << LowerBound(array, 4, 14) << endl;
	
	cout << UpperBound(array, 4, 14) << endl;
	
	cout << BinarySearch(array, 4, 14)<< endl;
	
}

int BinarySearch(int array[], int key, int len)
{
	int min = 0, max = len-1, mid;
	while(max >= min)
	{
		mid = (min+max)/2;
		if 		(key > array[mid]) min = mid + 1;
		else if (key < array[mid]) max = mid - 1;
		else if (key == array[mid]) return mid;		
	}
	return -1;
}
int LowerBound(int array[], int key, int len)
{
	int result = -1;
	int min = 0, max = len-1, mid;
	while(max >= min)
	{
		mid = (min+max)/2;
		if 		(key > array[mid]) min = mid + 1;
		else if (key < array[mid]) max = mid - 1;
		else if (key == array[mid]) {max=mid-1;result = mid;}		
	}
	return result;
}
int UpperBound(int array[], int key, int len)
{
	int result = -1;
	int min = 0, max = len-1, mid;
	while(max >= min)
	{
		mid = (min+max)/2;
		if 		(key > array[mid]) min = mid + 1;
		else if (key < array[mid]) max = mid - 1;
		else if (key == array[mid]) {min=mid+1;result = mid;}	
	}
	return result;
}





