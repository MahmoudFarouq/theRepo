#include <iostream>
#include <iomanip>
//#include "../Desktop/man.cpp"
#define FUN(a)(#a)

using namespace std;
int main()
{
	/*
		int8_t 		1 byte signed 		-128 to 127
		uint8_t 	1 byte unsigned 	0 to 255
		int16_t 	2 byte signed 		-32,768 to 32,767
		uint16_t 	2 byte unsigned 	0 to 65,535
		int32_t 	4 byte signed 		-2,147,483,648 to 2,147,483,647
		uint32_t 	4 byte unsigned 	0 to 4,294,967,295
		int64_t 	8 byte signed 		-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
		uint64_t 	8 byte unsigned 	0 to 18,446,744,073,709,551,615
	 */

	string mahmoud = "MAHMOUD";
	cout << FUN(mahmoud) << endl;
	uint16_t x(15);	//doesnt work with 8bit! why??
	cout << x << endl;

	char c = 'a';
	cout << static_cast<int>(c) << " \a" << (int)c << endl;

	std::cout << "Hello," " world!" << endl; // C++ will concatenate sequential string literals

	int octal = 012;
	int hexa  = 0x1F;
	int binary= 0b10101;
	cout << octal << " " << hexa << " " << binary << endl;

	int regVar(5);
	int regVar2{10};
	cout << regVar << ", " << regVar2 << endl;

	/*
		constexpr double gravity (9.8); // ok, the value of 9.8 can be resolved at compile-time
		constexpr int sum = 4 + 5; 		// ok, the value of 4 + 5 can be resolved at compile-time

		std::cout << "Enter your age: ";
		int age;
		std::cin >> age;
		//constexpr int myAge = age; // not okay, age can not be resolved at compile-time
	*/

	cout << ~-4 << endl;

	const unsigned int redBits = 0xFF000000;
    const unsigned int greenBits = 0x00FF0000;
    const unsigned int blueBits = 0x0000FF00;
    const unsigned int alphaBits = 0x000000FF;

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    unsigned int pixel;
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use bitwise AND to isolate red pixels, then right shift the value into the range 0-255
    unsigned char red = (pixel & redBits) >> 24;
    unsigned char green = (pixel & greenBits) >> 16;
    unsigned char blue = (pixel & blueBits) >> 8;
    unsigned char alpha = pixel & alphaBits;

    std::cout << "Your color contains:\n";
    std::cout << static_cast<int>(red) << " of 255 red\n";
    std::cout << static_cast<int>(green) << " of 255 green\n";
    std::cout << static_cast<int>(blue) << " of 255 blue\n";
    std::cout << static_cast<int>(alpha) << " of 255 alpha\n";

}










