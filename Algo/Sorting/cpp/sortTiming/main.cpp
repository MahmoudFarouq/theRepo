#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
typedef std::chrono::high_resolution_clock::time_point TimeVar;
#define timeNow() std::chrono::high_resolution_clock::now()
#define Duration(start, finish) std::chrono::duration_cast<std::chrono::microseconds>( finish - start ).count()

void insertion_sort_double(int array[], int len)
{
	for(int i = 1; i < len; i++)                        // go through the whole array
	{
		if(array[i-1] > array[i] )                      // if big element before small one
		{
			if(array[i] < array[i+1] && i < len-1)      //look for the next to the smaller, swap to make bigger in front
                                                        //(the small and the one smaller or bigger but not the one on last sorted)
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }

            int toBeMoved = array[i];                           // now we have the biggest -> smaller - > even smaller
			int secToBeMoved = i < len-1 ? array[i+1]:-1;       // the even smaller :D

            int index = i-1;                                    // LAST Sorted index
			while(toBeMoved < array[index] && index >= 0)       // go back in the array, and shift by two
			{
			    if(secToBeMoved != -1)
                    array[index+2] = array[index];              // if there are 2 elements with us
                else
                    array[index+1] = array[index];              // if only one element
				index--;
			}
			if(secToBeMoved != -1)
                array[index+2] = toBeMoved;                     //put the smaller
            else
                array[index+1] = toBeMoved;
            if(secToBeMoved != -1)                              // now for the even smaller, if exists
            {
                while(secToBeMoved < array[index] && index >= 0)
                {
                    array[index+1] = array[index];
                    index--;
                }
                array[index+1] = secToBeMoved;
            }
		}
	}
}

void insertion_sort(int array[], int len)
{
	for(int i = 1; i < len; i++)
	{
		if(array[i-1] > array[i] )
		{
			int toBeMoved = array[i];
			int index = i-1;
			while(toBeMoved < array[index] )
			{
				array[index+1] = array[index];
				index--;
			}
			array[index+1] = toBeMoved;
		}
	}
}
int* GenerateRandomList(int lo, int hi, int len)
{
    int* ls = new int[len];
    for(int i = 0; i < len; i++)
    {
        ls[i] = rand()%(hi-lo) + lo;
    }
    return ls;
}


int main()
{

	srand(time(0));
    ofstream ori_insertion, imp_insertion;

    ori_insertion.open("ori_insertion.txt");
    imp_insertion.open("imp_insertion.txt");

	for(int j = 0; j < 100; j++)
    {
        int* test = GenerateRandomList(20, 1000, 2000);
        TimeVar start = timeNow();
        insertion_sort(test, 2000);
        TimeVar finish = timeNow();
        int du = Duration(start, finish);
        ori_insertion << du << ',';
        delete[] test;
    }
    for(int j = 0; j < 100; j++)
    {
        int* test = GenerateRandomList(20, 1000, 2000);
        TimeVar start = timeNow();
        insertion_sort_double(test, 2000);
        TimeVar finish = timeNow();
        int du = Duration(start, finish);
        imp_insertion << du << ',';
        delete[] test;
    }
    ori_insertion.close();
    imp_insertion.close();
    return 0;
}
