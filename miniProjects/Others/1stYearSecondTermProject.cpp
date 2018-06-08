#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
struct chairs{int num; char avail;};
//functions
void choose_option();
void reserveOrCancel(bool bol);
void reset();
void money();
void classes(chairs*, int, int);
//global arrays
chairs *first_array = new chairs[20];
chairs *second_array = new chairs[40];
chairs *third_array = new chairs[50];
//global Variable
int total;
int main()
{
    reset();
}
void choose_option()
{
    system("cls");
    int choose;
    cout << "1) Ticket Reservation.\n";
    cout << "2) Ticket Cancellation.\n";
    cout << "3) Reset The Theater Reservation.\n";
    cout << "4) Exit.\n";
    cin >> choose;
    switch(choose)
    {
        case 1: reserveOrCancel(true); break;
        case 2: reserveOrCancel(false); break;
        case 3: reset(); break;
    }
}
void reserveOrCancel(bool bol)
{
    system("cls");
    int sec_choose;
    cout << "1) for First Class." << endl;
    cout << "2) for Second Class." << endl;
    cout << "3) for Third Class." << endl;
    cout << "4) back." << endl;
    cin >> sec_choose;
    int x = (bol == true? 1:-1);
	switch(sec_choose)
	{
		case 1: classes(first_array , 20, x*50); break;
		case 2: classes(second_array, 40, x*15); break;
		case 3: classes(third_array , 50, x*10); break;
		case 4: choose_option(); break;
	}
}
void classes(chairs* arry, int len, int cost)
{
    system("cls");
    int third_choose;
    for(int i = 0; i <len; i++)
    {
        if (i % 5 == 0) cout << endl;
        cout << setw(5) << arry[i].num << ", " << arry[i].avail;
    }
    cout << endl;
    cout << "which seat you want to reserve" << endl;
    cout << "OR press '0' to go see the Desired money: ";
    cin >> third_choose;
    if(third_choose != 0)
    {
        if(cost > 0)
            if (arry[third_choose-1].avail == 'O')
            {
                arry[third_choose-1].avail = 'X';
                total += cost;
            } else    cout << "Sorry, This seat is Unavailable" << endl;
        else
            if (arry[third_choose-1].avail == 'X')
            {
                arry[third_choose-1].avail = 'O';
                total += cost;
            } else    cout << "Sorry, This seat is Unavailable" << endl;
        classes(arry,len,cost);
    } else money();
}
void money()
{
    int x;
    cout << "the total cost is: " << total << " $"<< "\n Press '0' to go to main menu..";
    cin >> x;
    choose_option();
}
void reset()
{
    for(int i = 0; i <20; i++)  {first_array[i].num = i+1;first_array[i].avail = 'O';}
    for(int i = 0; i < 40; i++) {second_array[i].num = i+1;second_array[i].avail = 'O';}
    for(int i = 0; i < 50; i++) {third_array[i].num = i+1;third_array[i].avail = 'O';}
    total = 0;
    choose_option();
}
