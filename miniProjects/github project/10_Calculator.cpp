#include <iostream>
using namespace std;
float factorial(float a);
float power(float a, int pwr);
int main()
{
    while (true)
    {
    int choose;
    float x, y, x_radius, y_degree;
    cout << "Hi Mr.Unknown :)" << endl;
    cout << "Please chose one of the following options to be calculated." << endl;
    cout << "1) sin(x)                2) cos(x)              3) tan(x)\n" << endl;
    cout << "4) sin^-1(x)             5) cos^-1(x)           6) tan^-1(x)\n"<< endl;
    cout << "7) e^(x)                 8) ln(1+x)             9) ln(1-x)\n" << endl;
    cout << "You Want Num:  ";
    cin >> choose;
    while (choose < 1 || choose > 9)
    {
        cout << "retry.. ";
        cin >> choose;
    }
    cout << "Enter the Value of X: " ;
    cin >> x;
    x_radius = (22*x)/(180*7);
    switch (choose)
    {
        case 1:
            y = (x_radius) - (power(x_radius,3)/factorial(3)) + (power(x_radius,5)/factorial(5)) - (power(x_radius,7)/factorial(7));
            break;
        case 2:
            y = 1 - (power(x_radius,2)/factorial(2)) + (power(x_radius,4)/factorial(4)) - (power(x_radius,6)/factorial(6));
            break;
        case 3:
            y = (x_radius) + (power(x_radius,3)/3) + (2*power(x_radius,5)/15) + (17*power(x_radius,7)/315) + (62*power(x_radius,9)/2385);
            break;
        case 4:
            y = (x) + (power(x,3)/factorial(3)) + (power(x,5)/factorial(5)) + (power(x,7)/factorial(7)) + (power(x,9)/factorial(9));
            break;
        case 5:
            y = -(x) - (power(x,3)/factorial(3)) - (power(x,5)/factorial(5)) - (power(x,7)/factorial(7)) +(power(x,9)/factorial(9));
            break;
        case 6:
            y = (x) - (power(x,3)/3) + (power(x,5)/5) - (power(x,7)/7)+(power(x,9)/9) ;
            break;
        case 7:
            y = 1 + (power(x,1)/factorial(1)) + (power(x,2)/factorial(2))+ (power(x,3)/factorial(3)) + (power(x,4)/factorial(4)) + (power(x,5)/factorial(5)) + (power(x,6)/factorial(6))+(power(x,7)/factorial(7)) + (power(x,8)/factorial(8)) + (power(x,9)/factorial(9))+(power(x,10)/factorial(10)) + (power(x,11)/factorial(11)) + (power(x,12)/factorial(12)) + (power(x,13)/factorial(13));
            break;
        case 8:
            y = (x_radius) - (power(x_radius,2)/factorial(2)) + (power(x_radius,3)/factorial(3)) - (power(x_radius,4)/factorial(4));
            break;
        case 9:
            y = (- x_radius) - (power(x_radius,2)/factorial(2)) - (power(x_radius,3)/factorial(3)) - (power(x_radius,4)/factorial(4));
            break;
    }
    y_degree = ((y*180)/(22/7));
    switch(choose)
    {
        case 1:
        case 2:
        case 3: 
        case 7:
            cout << "The Result is: " << y << endl;
            break;
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
            cout << "The Result is: " << y_degree << endl;
            break;
    }
    }
}
float factorial(float a)
{
    float fac;
    if (a == 1){return 1;}
    else{fac = a*factorial(a-1);}
    return fac;
}
float power(float a, int pwr)
{
    float result = 1;
    if (pwr == 0){return 1;}
    else
    {
        for (int i = 0; i < pwr; i++)
            result *= a;
    }return result;
}

