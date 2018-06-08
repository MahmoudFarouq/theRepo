using System;
using System.Collections;
using System.Security.Cryptography;


/*
	Sort algorithms that are stable: insertion and merge
	! selection and shell AND QuickSOrt
*/
public delegate bool Comparer<T>(T f, T s);

public class SortingAlgorithms<T>
{
	public static Comparer<T> Greater;
	public static void SelectionSort(T[] array, Comparer<T> c)
	{
		Greater = c;
		for(int i = 0; i < array.Length; i++)
		{
			int min = i;
			for(int j = i; j < array.Length; j++)
			{
				if (Greater(array [j], array[min]))
					min = j;
			}
			T temp = array [min];
			array [min] = array [i];
			array [i] = temp;
		}
	}
	public static void InsertionSort(T[] array, Comparer<T> c)
	{
		Greater = c;
		for(int i = 1; i < array.Length; i++)
		{
			T toBeMoved = array [i];
			int j;
			for(j = i; j >= 0; j--)
			{
				if (Greater(array [j - 1],  toBeMoved)) {
					array [j] = array [j - 1];
				} else
					break;
			}
			array [j] = toBeMoved;
		}
	}
	public static void BubbleSort(T[] array, Comparer<T> c)
	{
		Greater = c;
		int len = array.Length;
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < len-1-i; j++)
			{
				if(Greater(array[j], array[j+1]))
				{
					T temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
	public static void ShellSort(T[] array, Comparer<T> c)
	{
		Greater = c;
		int N = array.Length;
		int h = 1;
		while (h < N / 3)
			h = 3 * h + 1;
		while(h >= 1)
		{
			//Normal InsertionSort
			for(int i = h; i < N; i++)
			{
				T toBeMoved = array [i];
				int j;
				for(j = i; j >= h; j-=h)
				{
					if (Greater(array [j - 1],  toBeMoved)) {
						array [j] = array [j - 1];
					} else
						break;
				}
				array [j] = toBeMoved;
			}
			h /= 3;
		}
	}

	public static void MergeSort(T[] array, T[] aux, int left, int right, Comparer<T> c)
	{
		Greater = c;
		if (left < right) {
			int mid = left + (right-left)/2;
			MergeSort (array, aux, left, mid, Greater);
			MergeSort (array, aux,  mid + 1, right, Greater);

			Merge (array, aux, left, mid, right);
		}
	}
	private static void Merge(T[] array, T[] aux, int left, int mid, int right)
	{
		int lenL, lenR;
		lenL = mid-left+1;
		lenR = right - mid;

		for(int i = 0; i < lenL+lenR; i++) {aux[left+i] = array[left+i];}

		int leftIndex = 0; 
		int rightIndex= 0;
		int k = left;


		while( leftIndex < lenL && rightIndex < lenR )
		{
			if( Greater(aux[left+leftIndex], aux[mid+1+rightIndex]))
			{
				array [k] = aux [left + leftIndex];
				leftIndex++;
			}
			else
			{
				array[k] = aux[mid+1+rightIndex]; 
				rightIndex++; 
			}
			k++;
		}
		while (leftIndex < lenL)
		{
			array [k] = aux [left + leftIndex];
			leftIndex++;
			k++;
		}
		while (rightIndex < lenR)
		{
			array[k] = aux[mid+1+rightIndex];
			rightIndex++;
			k++;
		}
	}

	public static void QuickSort(T[] array, Comparer<T> c)
	{
		Greater = c;
		KnuthShuffle (array);
		QuickSort (array, 0, array.Length-1);
	}
	public static void QuickSort(T[] array, int lo, int hi)
	{
		if (hi <= lo)
			return;
		int j = Partition (array, lo, hi);
		QuickSort (array, lo, j-1);
		QuickSort (array, j+1, hi);
	}
	private static int Partition(T[] array, int lo, int hi)
	{
		int i = lo;
		int j = hi+1;
		while(true)
		{
			while (Greater (array [++i], array [lo]))
				if (i >= hi)
					break;
			while (Greater (array [lo], array [--j]))
				if (j <= lo)
					break;
			if (i >= j)
				break;
			Exchange (array, i, j);
		}
		Exchange (array, lo, j);
		return j;
	}
	public static T QuickSelect(T[] array, int k, Comparer<T> c)
	{
		Greater = c;
		KnuthShuffle (array);
		int lo = 0;
		int hi = array.Length - 1;

		while( hi > lo )
		{
			int j = Partition (array, lo, hi);
			if (j > k)
				hi = j - 1;
			else if (j < k)
				lo = j + 1;
			else
				return array [k];
		}
		return array [k];
	}

	public static void HeapSort(T[] arr, Comparer<T> c)
	{
		Greater = c;
		int n = arr.Length;
		for (int i = n/2; i > 0; i--)
			Sink (arr, i, n);
		while(n > 1)
		{
			Exchange (arr, 1, --n);
			Sink (arr, 1, n);
		}
	}
	private static void Sink(T[] tree, int k, int lastIndex)
	{
		while( k*2 < lastIndex-1 )
		{
			int j = k * 2;
			if (j < lastIndex && !Greater (tree [j], tree [j + 1]))
				j++;
			if (Greater (tree [k], tree [j]))
				break;
			Exchange (tree, k, j);
			k = j;
		}
	}
	private static void Exchange(T[] arr, int k, int k2)
	{
		T temp = arr [k];
		arr [k] = arr [k2];
		arr [k2] = temp;
	}

	public static void CountingSort(int[] array)
	{
		int newLen = FindMax(array)+1;
		int[] newArray = new int[newLen];
		int len = array.Length;
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
	public static int[] BeadSort(int[] arr)
	{
		int max = 0;
		for (int i = 0; i < arr.Length; i++)
			if (arr [i] > max)
				max = arr [i];

		char[,] grid = new char[arr.Length, max];
		int[] levelcount = new int[max];
		for (int i = 0; i < max; i++) {
			levelcount [i] = 0;
			for (int j = 0; j < arr.Length; j++)
				grid [j, i] = '_';
		}
		for (int i = 0; i < arr.Length; i++) {
			int num = arr [i];
			for (int j = 0; num > 0; j++) {
				grid [levelcount [j]++, j] = '*';
				num--;
			}
		}
		int[] sorted = new int[arr.Length];
		for (int i = 0; i < arr.Length; i++) {
			int putt = 0;
			for (int j = 0; j < max && grid [arr.Length - 1 - i, j] == '*'; j++)
				putt++;
			sorted [i] = putt;
		}
		return sorted;
	}


	private static int FindMax(int[] array)
	{
		int max = 0;
		int len = array.Length;
		for(int i = 0; i < len; i++)
		{
			max = (max > (array[i]) ? max:array[i]);
		}
		return max;
	}

	public static void KnuthShuffle(T[] array)
	{
		Random rnd = new Random ();
		int len = array.Length;
		for(int i = 0; i < len; i++)
		{
			int j = rnd.Next (0, i);
			T temp = array [i];
			array [i] = array [j];
			array [j] = temp;
		}
	}
}
