using System;

public class ThreeSum
{
	public ThreeSum ()
	{
		
	}
	public static int Count(int[] arr)
	{
		int count = 0;
		for(int i = 0; i < arr.Length; i++)
		{
			for(int j = i+1; j < arr.Length; j++)
			{
				for(int k = j+1; k < arr.Length; k++)
				{
					if( arr[i]+arr[j]+arr[k] == 0 )
						count++; 
				}
			}
		}
		return count;
	}
	public static int BetterCount(int[] arr)
	{
		int count = 0;
		for(int i = 0; i < arr.Length; i++)
		{
			for(int j = i+1; j < arr.Length; j++)
			{
				if(BinarySearch (arr, -( arr[i]+arr[j] )) != -1 )
					count++; 
			}
		}
		return count;
	}
	public static int BinarySearch(int[] arr, int min, int max, int key)
	{
		if (max >= min) {
			int mid = min + (max - min) / 2;
			if (arr [mid] > key)
				return BinarySearch (arr, min, mid - 1, key);
			else if (arr [mid] < key)
				return BinarySearch (arr, mid + 1, max, key);
			else if (arr [mid] == key)
				return mid;
		}
		return -1;
	}
	public static int BinarySearch(int[] arr, int key)
	{
		int min = 0;
		int max = arr.Length - 1;
		while (max >= min) 
		{
			int mid = min + (max - min) / 2;
			if (arr [mid] > key)
				max = mid - 1;
			else if (arr [mid] < key)
				min = mid + 1;
			else if (arr [mid] == key)
				return mid;
		}
		return -1;
	}
}















