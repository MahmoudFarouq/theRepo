#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
void Pyramid();
void Pyramid2();
void square();
using namespace std;
int main()
{
    srand(time(0));
    while(true)
    {
        system("cls");
        if (rand() %2 ==0)
        {
            Pyramid2();
        }
        else
        {
            Pyramid();
        }
    }
}
int Random()
{
    return rand()%20;
}
void Pyramid()
{
    int s,ss;
    do{
    s = rand()%30;
    }while(s <= 5);
    do{
    ss = rand()%s;
    }while(ss <= 3);
    int sss = rand()%ss;
    for (int i =0; i < s; i++)
    {
        for(int w = 0; w < i; w++)
        {
            cout << " ";
        }
        for(int j = ((s-i)*2-1); j > 0; j--)
        {
            cout << "*";
        }
        for(int w = 0; w < i*2+1; w++)
        {
            cout << " ";
        }
        for(int j = ((ss-i)*2-1); j > 0; j--)
        {
            cout << "*";
        }
        for(int w = 0; w < i*2+1; w++)
        {
            cout << " ";
        }
        for(int j = ((sss-i)*2-1); j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pyramid2()
{
    int s;
    do{
    s = rand()%30;
    }while (s <=5);
    for(int i =0; i < s; i++)
    {
        for(int j = s; j > i; j--)
        {
            cout << " ";
        }
        int q =i;
        while(q >= 0)
        {
            cout << "*";
            q--;
        }
        q =i;
        while(q > 0)
        {
            cout << "*";
            q--;
        }
        for(int j = s; j > i; j--)
        {
            cout << " ";
        }
        for(int j = s; j > i; j--)
        {
            cout << " ";
        }
        q =i-5;
        while(q >= 0)
        {
            cout << "*";
            q--;
        }
        q =i-5;
        while(q > 0)
        {
            cout << "*";
            q--;
        }
        for(int j = s; j > i; j--)
        {
            cout << " ";
        }
        for(int j = s; j > i; j--)
        {
            cout << " ";
        }
        q =i-10;
        while(q >= 0)
        {
            cout << "*";
            q--;
        }
        q =i-10;
        while(q > 0)
        {
            cout << "*";
            q--;
        }
        for(int j = s; j > i; j--)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void square()
{
    int s = rand()%20;
    for (int i =0; i < s; i++)
    {
        for(int j =0;j < s; j++)
        {
            if(i == 0 || i ==s-1)
                cout << "$";
            else {cout << "$" << setw(s-1) << "$";
                j = s;}
        }
        cout << endl;
    }
}
