using System;

public class Search
{
	public Search ()
	{
	}
	public static int BinarySearch(int[] arr, int key)
	{
		int min = 0;
		int max = arr.Length - 1;
		int mid = 0;
		while (max >= min) 
		{
			mid = min + (max - min) / 2;
			if (arr [mid] > key)
				max = mid - 1;
			else if (arr [mid] < key)
				min = mid + 1;
			else if (arr [mid] == key)
				return mid;
		}
		return -1;
	}
	public static int BinarySearch_UB(int[] arr, int key)
	{
		int min = 0;
		int max = arr.Length - 1;
		int mid = 0;
		while (max >= min) 
		{
			mid = min + (max - min) / 2;
			if (arr [mid] > key)
				max = mid - 1;
			else if (arr [mid] < key)
				min = mid + 1;
			else if(arr [mid] == key)
				min++;	//if key exists
		}
		return mid;	//if it doesnt exist
	}
	public static int BinarySearch_LB(int[] arr, int key)
	{
		int min = 0;
		int max = arr.Length - 1;
		int mid = 0;
		while (max >= min) 
		{
			mid = min + (max - min) / 2;
			if (arr [mid] > key)
				max = mid - 1;
			else if (arr [mid] < key)
				min = mid + 1;
			else if (arr [mid] == key)
				max--;
		}
		return mid;
	}
}

