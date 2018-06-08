#include <iostream>
#include <string>
#include "level_2.h"
#include "level_3.h"
#include "level_9.h"
#include "level_10.h"
#include <windows.h>

using namespace std;

char Map[20][100] = {"########################################################",
                    "#  #  #                                           *  ! #",
                    "#########          Stay Alive_:)             ###*###*  #",
                    "#      #  ##############                     ###*###  *#",
                    "# ########                *        ######  #           #",
                    "# #     *       ########################### ##         #",
                    "#   #########   ##############              ##         #",
                    "#   ##                            ########  ##         #",
                    "#   ##         #######  #######   ## $$ ##  ## #####   #",
                    "#   ##    ###  ##   ##  ##   ##   ## $$ ##  ## #   #   #",
                    "#   ##     ##  ##   ##  ##   ##   ########  ## #####   #",
                    "#   ##     ##  ##   ##  ##   ##         ##  ## #       #",
                    "#   #########  #######  #######   ########  ## ####### #",
                    "#                       *          *                   #",
                    "######  #########   #######   ######   ########  ##### #",
                    "######  #########   #######     ##     ####### #  #### #",
                    "#              ##               ##  ##                 #",
                    "# @            ##                   ##                 #",
                    "########################################################"};
int Gamespeed = 100;
int Level = 1;
int hp = 5;
int maxhp = 5;
bool stopgame = false;
string name;
int tet;


int main()
{
        cout << "Please Enter Your Name: ";
        cin >> name;
        cout << "#################################################" << endl;
        cout << "# HI " << name << "..                                 #" << endl;
        cout << "# ----------                                    #" << endl;
        cout << "#                                               #" << endl;
        cout << "# This is 'PackMaC'..                           #" << endl;
        cout << "# --------------------                          #" << endl;
        cout << "# A very Simple Game That Developed By..        #" << endl;
        cout << "#                                               #" << endl;
        cout << "# 'Mahmoud Fraouk'                              #" << endl;
        cout << "# -----------------                             #" << endl;
        cout << "#                                               #" << endl;
        cout << "# I Built It Using some Stars, Hashes, Marks..  #" << endl;
        cout << "# And '@', You :)                               #" << endl;
        cout << "#                                               #" << endl;
        cout << "#            HOPE YOU ALL LIKE IT :)            #" << endl;
        cout << "#                                               #" << endl;
        cout << "# 1) Next        2) Exit                        #" << endl;
        cout << "#                                               #" << endl;
        cout << "#################################################" << endl;
        cin >> tet;
        if (tet == 2)
        {
            stopgame = true;
        }

        cout << "#################################################" << endl;
        cout << "#                                               #" << endl;
        cout << "# Ok " << name << "..                                #" << endl;
        cout << "#                                               #" << endl;
        cout << "# Now This Is a Game consists of 10 Levels,     #" << endl;
        cout << "#                                               #" << endl;
        cout << "# That You Have To Pass Successfully So You     #" << endl;
        cout << "#                                               #" << endl;
        cout << "# Can Win.                                      #" << endl;
        cout << "#                                               #" << endl;
        cout << "# You Start With 5 Lives and.....               #" << endl;
        cout << "#                                               #" << endl;
        cout << "# Ok, Lets Discover it, yourself :)             #" << endl;
        cout << "#                                               #" << endl;
        cout << "#                                               #" << endl;
        cout << "#             Stars With Level 1.               #" << endl;
        cout << "#                                               #" << endl;
        cout << "#          1) Enter..       2)Exit              #" << endl;
        cout << "#################################################" << endl;
        cin >> tet;

    while(stopgame == false && Level == 1 && hp > 0)
    {
        cout << "Level : " << Level << endl;
        system("cls");
        for(int y = 0; y < 20; y++)
        {
            cout << Map[y] << endl;
        }
        cout << "Lives: " << hp << "/" << maxhp << endl;
        for(int y = 0; y < 20; y++)
        {
            for(int x = 0; x < 100 ; x++)
            {

                switch (Map[y][x])
                {
                    case '#':
                    {
                        Map [y][x] = 215;
                    }
                    case '@':
                    {
                        if (GetAsyncKeyState(VK_UP) != 0)
                        {
                            int y2 = (y-1);

                            switch (Map[y2][x])
                            {
                                case ' ':
                                {
                                    Map[y][x] = ' ';
                                    y -= 1;
                                    Map[y2][x] = '@';
                                }break;
                                case '!':
                                {
                                    Level = 2;
                                }break;
                                case '*':
                                    {hp -= 1;
                                    Map[y][x] = ' ';
                                    y -= 1;
                                    Map[y2][x] = '@';}
                            }
                        }
                        if (GetAsyncKeyState(VK_DOWN) != 0)
                        {
                            int y2 = (y+1);

                            switch (Map[y2][x])
                            {
                                case ' ':
                                {
                                    Map[y][x] = ' ';
                                    y += 1;
                                    Map[y2][x] = '@';
                                }break;
                                case '!':
                                {
                                    Level = 2;
                                }break;
                                case '*':
                                    {hp -= 1;
                                    Map[y][x] = ' ';
                                    y += 1;
                                    Map[y2][x] = '@';}

                            }
                        }
                        if (GetAsyncKeyState(VK_RIGHT) != 0)
                        {
                            int x2 = (x+1);

                            switch (Map[y][x2])
                            {
                                case ' ':
                                {
                                    Map[y][x] = ' ';
                                    x += 1;
                                    Map[y][x2] = '@';
                                }break;
                                case '!':
                                {
                                    Level = 2;
                                }break;
                                case '*':
                                    {hp -= 1;
                                    Map[y][x] = ' ';
                                    x += 1;
                                    Map[y][x2] = '@';}
                            }
                        }
                        if (GetAsyncKeyState(VK_LEFT) != 0)
                        {
                            int x2 = (x-1);

                            switch (Map[y][x2])
                            {
                                case ' ':
                                {
                                    Map[y][x] = ' ';
                                    x -= 1;
                                    Map[y][x2] = '@';
                                }break;
                                case '!':
                                {
                                    Level = 2;
                                }break;
                                case '*':
                                    {hp -= 1;
                                    Map[y][x] = ' ';
                                    x -= 1;
                                    Map[y][x2] = '@';}

                            }
                        }
                    }

                }

            }
        }
        Sleep(Gamespeed);
    }
    if(stopgame == false && Level == 2 && hp > 0)
    {
        system("cls");
        cout << "##########################################" << endl;
        cout << "#              Excellent..               #" << endl;
        cout << "#                                        #" << endl;
        cout << "#  'NO Great Thing is Created SUDDENLY'  #" << endl;
        cout << "#                                        #" << endl;
        cout << "#     1) Next Level        2) Exit       #" << endl;
        cout << "##########################################" << endl;
        cin >> tet;
        if (tet == 2)
        {
            stopgame = true;
        }
        level_2 l2;
        l2.lvl2(hp);
        system("cls");
        cout << "You Have completed The Game, WILLDONE :) \n\n" << endl;
        cout << "################################################"<< endl;
        cout << "#     *                *                 *     #"<< endl;
        cout << "#     **              ***               **     #"<< endl;
        cout << "#     ***            *****             ***     #"<< endl;
        cout << "#     ****          *******           ****     #"<< endl;
        cout << "#     *****        *********         *****     #"<< endl;
        cout << "#     ******      ***********       ******     #"<< endl;
        cout << "#     *******    *************     *******     #"<< endl;
        cout << "#     ********  ***************   ********     #"<< endl;
        cout << "#     ************************************     #"<< endl;
        cout << "#     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     #"<< endl;
        cout << "#     ************************************     #"<< endl;
        cout << "#     **      #    THE WINNER    #      **     #"<< endl;
        cout << "#     ************************************     #"<< endl;
        cout << "#                                              #"<< endl;
        cout << "#                                              #"<< endl;
        cout << "################################################"<< endl;
        system("pause");
        return EXIT_SUCCESS;
    }if(hp < 0){
        cout << "Sorry.. You LOSE, Keep Trying";
        system("pause");
        int fo;
        cin >> fo;
        return EXIT_SUCCESS;
    }

}
