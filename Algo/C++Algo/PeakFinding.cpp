#include <iostream>
using namespace std;

int array2D[4][4] = {{1,2,3,4},
					{5,6,7,8},
					{9,20,11,12},
					{13,14,50,0}};

struct Point{int x; int y;};

int PeakFind1D(int array[], int len);
int PeakFind2D(int x, int y);

int main()
{
	
}

int PeakFind1D(int array[], int len)
{
	int min = 0, max = len-1, mid;
	while(max >= min)
	{
		mid = (min+max)/2;
		if 		(array[mid+1] > array[mid]) min = mid + 1;
		else if (array[mid-1] > array[mid]) max = mid - 1;
		else return array[mid];		
	}
	return -1;
}
int PeakFind2D(int x, int y)
{
	// Gready Ascent algorithm
	Point point;
	point.x = x/2;
	point.y = y/2;
	while(point.x < x && point.y < y)
	{
			 if(array2D[point.x][point.y] < array2D[point.x-1][point.y]) point.x -= 1;
		else if(array2D[point.x][point.y] < array2D[point.x+1][point.y]) point.x += 1;
		else if(array2D[point.x][point.y] < array2D[point.x][point.y-1]) point.y -= 1;
		else if(array2D[point.x][point.y] < array2D[point.x][point.y+1]) point.y += 1;
		else return array2D[point.x][point.y];
	}
	point.x = ( point.x == x ? point.x-1:point.x);
	point.y = ( point.y == y ? point.y-1:point.y);
	return array2D[point.x][point.y];
}
