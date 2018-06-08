/*
	Hanoi Tower Problem
	-------------------
	It consists of three Bars and a number of disks of different sizes,
	which can slide onto any bar. 
	The puzzle starts with the disks in a neat stack in ascending order of size on one rod,
	the smallest at the top, thus making a conical shape.
	
	The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
		1: Only one disk can be moved at a time.
		2: Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
		3: No disk may be placed on top of a smaller disk.

	Time complexity
	---------------
	O(2^n -1 ), where n is the number of disks  

	Space complexity
	----------------
	O( n ), where n is the number of disks 

*/
#include <iostream>
#include <math.h>
using namespace std;

void Hanoi(int disks, char a_bar, char b_bar, char c_bar){
    if(disks == 1)
        cout << "Move disk " << disks << " from " << a_bar << " to " << c_bar << endl;
    else{
        Hanoi(disks-1, a_bar, c_bar, b_bar);
        cout << "Move disk " << disks << " from " << a_bar << " to " << c_bar << endl;
        Hanoi(disks-1, b_bar, a_bar, c_bar);
    }
}

int main()
{
	int disks;
	cout << "Enter the number of disks: " << endl;
	cin >> disks;
	Hanoi(disks, 'A', 'B', 'C');
	int moves = pow(2, disks) - 1;
	cout << "It took " << moves << " moves. " << endl;
	return 0;
}

