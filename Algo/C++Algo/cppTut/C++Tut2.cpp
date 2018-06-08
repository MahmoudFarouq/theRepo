#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "FOO.cpp"
#include "DOO.cpp"
int value(5);
using namespace std;
unsigned int PRNG();
//typedef double distance_t; // define distance_t as an alias for type double
// The following two statements are equivalent:
//double howFar;
//distance_t howFar;

typedef vector<pair<string, int> > pairlist_t; // make pairlist_t an alias for this crazy type

// Declare a new enumeration named Color
enum Color
{
    // Here are the enumerators
    // These define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_WHITE,
    COLOR_CYAN,
    COLOR_YELLOW,
    COLOR_MAGENTA
    // for maximum compatibility, the last enumerator should not have a comma
};  // however the enum itself must end with a semicolon

int main()
{
	using DOO::doSomeThing;
	cout << FOO::doSomeThing(5, 10) << endl;

	char c = 97;
	cout << c << endl;

	int value(10);
	cout << "global: " << ::value << endl;
	cout << "local: " << value << endl;

	int x = 3.2;			//implicit type conversion
	cout << x << endl;

	int i1 = 10;
	int i2 = 4;
	float f = (float)i1 / i2; //Explicit type conversion
	cout << f << endl;

	Color paint = COLOR_WHITE;
	Color house(COLOR_BLUE);
	cout << paint << ", " << house << endl;

	cout << Color(COLOR_BLUE) << endl;


	//auto autoo = 0;
	//cin >> autoo;

	//nice Feature
	tryAgain:
	int z;
	cin >> z;
	if(z != 0) goto tryAgain;

	/*
	int s = 0;
	goto skip; // invalid forward jump
    s = 5;
	skip:
		s += 3; // what would this even evaluate to?
		cout << s << endl;
	*/

	for(int i = 0; i < 50; i++)
	{
		cout << PRNG() << endl;
	}



	exit(0);
}

unsigned int PRNG()
{
    // our initial starting seed is time(0)
    static unsigned int seed = time(0);
    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // very hard for someone to predict what the next number is
    // going to be from the previous one.
    seed = (8253729 * seed + 2396403);
    // Take the seed and return a value between 0 and 32767
    return seed  % 32768;
}








