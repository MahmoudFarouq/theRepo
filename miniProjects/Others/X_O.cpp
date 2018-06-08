#include <iostream>
#include <windows.h>
#include <map>
using namespace std;
char player, CPU;
void check(char x);
bool result();
void print();
char winner;
int counter = 0;

map<char, char> myMap;

int main()
{
    for(int i = 1; i <= 9; i++)
    {
        myMap[i+48] = i+48;
    }
    cout << "Hi!, This is TIC TAC TOE Game" << endl;
    cout << "which symbol you would like to take?! (X,O)" << endl;
    cin >> player;
    if (player == 'x' || player == 'X') {CPU = 'O';player = 'X';}
    else if (player == 'o' || player == 'O') {CPU = 'X';player = 'O';}
    else{cout << "i will take it as you are 'X', and I'm 'O'." << endl; player = 'X'; CPU = 'O';}
    //first step
    if (player == 'X') myMap['5'] = 'O';
    bool won = false;
    while(result() == 0)
    {
        print();
    }
    print();
    if(winner == CPU){cout << "CPU Wins! \nsorry you lose, try again.." << endl;}
    else if (winner == player)  {cout << "Wow!!.. You win :)" << endl;}
    else if(counter == 9) {cout << "Draw!.." << endl;}
}
void print()
{
    system("CLS");
    cout << "#########################" << endl;
    cout << "#       #       #       #" << endl;
    cout << "#   "<< myMap['1'] << "   #   "<< myMap['2'] << "   #   "<< myMap['3'] << "   #" << endl;
    cout << "#       #       #       #" << endl;
    cout << "#########################" << endl;
    cout << "#       #       #       #" << endl;
    cout << "#   "<< myMap['4'] << "   #   "<< myMap['5'] << "   #   "<< myMap['6'] << "   #" << endl;
    cout << "#       #       #       #" << endl;
    cout << "#########################" << endl;
    cout << "#       #       #       #" << endl;
    cout << "#   "<< myMap['7'] << "   #   "<< myMap['8'] << "   #   "<< myMap['9'] << "   #" << endl;
    cout << "#       #       #       #" << endl;
    cout << "#########################\n" << endl;
    char input;
    if(result() == 0){
        cout << "your turn.." << endl;
        cin >> input;
        while (myMap[input] == 'X' || myMap[input] == 'O') {cout << "Wrong Input: ";cin >> input;}
    }
    myMap[input] = player;
    check(input);
}
bool result()
{
    for(int i = 1; i <= 9; i+=3)
        {if (myMap[i+48] == myMap[i+1+48] && myMap[i+48] == myMap[i+2+48]){winner = myMap[i+48];return 1;}}
    for(int i = 1; i <= 3; i++)
        {if (myMap[i+48] == myMap[i+3+48] && myMap[i+48] == myMap[i+6+48]){winner = myMap[i+3+48];return 1;}}
    if (myMap['1'] == myMap['5'] && myMap['1'] == myMap['9'])
        {winner = myMap['1'];return 1;}
    if (myMap['3'] == myMap['5'] && myMap['3'] == myMap['7'])
        {winner = myMap['3'];return 1;}
    counter = 0;
    for(int i = 1; i <= 9; i++)
        {if (myMap[i+48] == 'X' || myMap[i+48] == 'O'){counter++;}}
    if (counter == 9)
        {return -1;}
    return 0;
}
void check(char x)
{
    // x == 5
         if(myMap['1'] == myMap['5'] && myMap['9'] == '9') myMap['9'] = CPU;
    else if(myMap['9'] == myMap['5'] && myMap['1'] == '1') myMap['1'] = CPU;
    else if(myMap['6'] == myMap['5'] && myMap['4'] == '4') myMap['4'] = CPU;
    else if(myMap['4'] == myMap['5'] && myMap['6'] == '6') myMap['6'] = CPU;
    else if(myMap['8'] == myMap['5'] && myMap['2'] == '2') myMap['2'] = CPU;
    else if(myMap['2'] == myMap['5'] && myMap['8'] == '8') myMap['8'] = CPU;
    else if(myMap['7'] == myMap['5'] && myMap['3'] == '3') myMap['3'] = CPU;
    else if(myMap['3'] == myMap['5'] && myMap['7'] == '9') myMap['7'] = CPU;
    //x == 8
    else if(myMap['7'] == myMap['8'] && myMap['9'] == '9') myMap['9'] = CPU;
    else if(myMap['9'] == myMap['8'] && myMap['7'] == '7') myMap['7'] = CPU;
    else if(myMap['5'] == myMap['8'] && myMap['2'] == '2') myMap['2'] = CPU;
    else if(myMap['2'] == myMap['8'] && myMap['5'] == '5') myMap['5'] = CPU;
    //x == 4
    else if(myMap['5'] == myMap['4'] && myMap['6'] == '6') myMap['6'] = CPU;
    else if(myMap['6'] == myMap['4'] && myMap['5'] == '5') myMap['5'] = CPU;
    else if(myMap['1'] == myMap['4'] && myMap['7'] == '7') myMap['7'] = CPU;
    else if(myMap['7'] == myMap['4'] && myMap['1'] == '1') myMap['1'] = CPU;
    //x == 6
    else if(myMap['5'] == myMap['6'] && myMap['4'] == '4') myMap['4'] = CPU;
    else if(myMap['4'] == myMap['6'] && myMap['5'] == '5') myMap['5'] = CPU;
    else if(myMap['3'] == myMap['6'] && myMap['6'] == '6') myMap['6'] = CPU;
    else if(myMap['6'] == myMap['6'] && myMap['3'] == '3') myMap['3'] = CPU;
    //x == 2
    else if(myMap['5'] == myMap['2'] && myMap['8'] == '8') myMap['8'] = CPU;
    else if(myMap['8'] == myMap['2'] && myMap['5'] == '5') myMap['5'] = CPU;
    else if(myMap['3'] == myMap['2'] && myMap['1'] == '1') myMap['1'] = CPU;
    else if(myMap['1'] == myMap['2'] && myMap['3'] == '3') myMap['3'] = CPU;
    //x == 1
    else if(myMap['2'] == myMap['1'] && myMap['3'] == '3') myMap['3'] = CPU;
    else if(myMap['3'] == myMap['1'] && myMap['2'] == '2') myMap['2'] = CPU;
    else if(myMap['4'] == myMap['1'] && myMap['7'] == '7') myMap['7'] = CPU;
    else if(myMap['7'] == myMap['1'] && myMap['4'] == '4') myMap['4'] = CPU;
    else if(myMap['5'] == myMap['1'] && myMap['9'] == '9') myMap['9'] = CPU;
    else if(myMap['9'] == myMap['1'] && myMap['5'] == '5') myMap['5'] = CPU;
    //x == 7
    else if(myMap['1'] == myMap['7'] && myMap['4'] == '4') myMap['4'] = CPU;
    else if(myMap['4'] == myMap['7'] && myMap['1'] == '1') myMap['1'] = CPU;
    else if(myMap['8'] == myMap['7'] && myMap['9'] == '9') myMap['9'] = CPU;
    else if(myMap['9'] == myMap['7'] && myMap['8'] == '8') myMap['8'] = CPU;
    else if(myMap['5'] == myMap['7'] && myMap['3'] == '3') myMap['3'] = CPU;
    else if(myMap['3'] == myMap['7'] && myMap['5'] == '5') myMap['5'] = CPU;
    //x == 3
    else if(myMap['1'] == myMap['3'] && myMap['2'] == '2') myMap['2'] = CPU;
    else if(myMap['2'] == myMap['3'] && myMap['1'] == '1') myMap['1'] = CPU;
    else if(myMap['6'] == myMap['3'] && myMap['9'] == '9') myMap['9'] = CPU;
    else if(myMap['9'] == myMap['3'] && myMap['6'] == '6') myMap['6'] = CPU;
    else if(myMap['5'] == myMap['3'] && myMap['7'] == '7') myMap['7'] = CPU;
    else if(myMap['7'] == myMap['3'] && myMap['5'] == '5') myMap['5'] = CPU;
    //x == 9
    else if(myMap['1'] == myMap['9'] && myMap['5'] == '5') myMap['5'] = CPU;
    else if(myMap['5'] == myMap['9'] && myMap['1'] == '1') myMap['1'] = CPU;
    else if(myMap['6'] == myMap['9'] && myMap['3'] == '3') myMap['3'] = CPU;
    else if(myMap['3'] == myMap['9'] && myMap['6'] == '6') myMap['6'] = CPU;
    else if(myMap['7'] == myMap['9'] && myMap['8'] == '8') myMap['8'] = CPU;
    else if(myMap['8'] == myMap['9'] && myMap['7'] == '7') myMap['7'] = CPU;
    else
    {
             if (myMap['5'] == '5') myMap['5'] = CPU;
        else if (myMap['1'] == '1') myMap['1'] = CPU;
        else if (myMap['3'] == '3') myMap['3'] = CPU;
        else if (myMap['2'] == '2') myMap['2'] = CPU;
        else if (myMap['9'] == '9') myMap['9'] = CPU;
        else if (myMap['7'] == '7') myMap['7'] = CPU;
        else if (myMap['8'] == '8') myMap['8'] = CPU;
        else if (myMap['4'] == '4') myMap['4'] = CPU;
        else if (myMap['6'] == '6') myMap['6'] = CPU;
    }
}

