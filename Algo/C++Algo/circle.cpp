#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int lines = 15;
    int dec = int(lines/2.5);
    int spaces = lines + dec;
    int spa=3;
    for(int i = 0; i < lines; i++)
    {
        if(dec > -8)
        {
            for(int j = spaces; j > 0; j--)
            {
                cout << " ";
            }
            cout << "**";
            for(int k = 0; k < spa; k++)
            {
                cout << " ";
            }
            if(dec*dec <= 4)
                cout << "**\n\n";
            else 
                cout << "**\n";
            spa += dec*2;
            spaces -= dec;
            dec--;
        }
    }
}
