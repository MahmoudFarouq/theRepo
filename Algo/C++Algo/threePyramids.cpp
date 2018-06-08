#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    int s;
    int counter =0;
    int counter2 =0;
    do{s = rand()%30;}while(s <= 15);
    for (int i =0; i<s*3-12; i++) cout << " #";
    cout << endl;
    for(int i =0; i < s; i++)
    {
        cout << " #";
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
        if(counter < 10)
        {
            for(int j = 5; j < s+1; j++)
            {
                cout << " ";
            }
        }
        else
        {
            for(int j = s; j > i; j--)
            {
                cout << " ";
            }
        }
        counter++;
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
        if(counter < 10)
        {
            for(int j = 5; j < s; j++)
            {
                cout << " ";
            }
        }
        else
        {
            for(int j = s; j > i; j--)
            {
                cout << " ";
            }
        }
        counter++;
        if(counter2 < 20)
        {
            for(int j = 10; j < s+1; j++)
            {
                cout << " ";
            }
        }
        else
        {
            for(int j = s; j > i; j--)
            {
                cout << " ";
            }
        }
        counter2++;
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
        if(counter2 < 20)
        {
            for(int j = 10; j < s; j++)
            {
                cout << " ";
            }
        }
        else
        {
            for(int j = s; j > i; j--)
            {
                cout << " ";
            }
        }
        counter2++;
        cout << "#";
        cout << endl;
    }
    for (int i =0; i<s*3-12; i++) cout << " #";
    cout << endl;
}
