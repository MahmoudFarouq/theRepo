#include "level_9.h"
#include <iostream>
#include <windows.h>
#include "level_10.h"
using namespace std;
level_9::level_9()
{
    cout << "Level .. " << endl;
}

int level_9::lvl9(int x)
{
int w = 0;
char Map[25][60] = {"# # # # # # # # # # # # # # # # # # # # # # # # # # # #",
"# * # **********     ***** # *****     ********** # * #",
"# *** # ******   ***   *** # ***   ***   ****** # *** #",
"# ***** # **   ***   *****   *****   ***   ** # ***** #",
"# ******     *******   *** # ***   ********    ****** #",
"# ****   ** # ****   ***** # *****   **** # **   **** #",
"# ******   ** # ****   *** # ***   **** # **   ****** #",
"# ****   ****** # ****   * # *   **** # ******   **** #",
"# ****** ******** # ***  * # *  *** # ******** ****** #",
"# ****   ********** # * ** # ** * # **********   **** #",
"# ****  ************* # ** # ** # *************  **** #",
"# *****  ************** #  #  # **************  ***** #",
"# ******  ***********   ** # **   ***********  ****** #",
"# ******* ********* # *  * # *  * # ********* ******* #",
"# ******* ******* # *   ** # **   * # ******* ******* #",
"# ****    ***** # ****   * # *   **** # *****   ***** #",
"# ***  ****** # ****   *** # ***   **** # ******  *** #",
"# **  ***** # ****   ***** # *****   **** # *****  ** #",
"# *  **** # *******   **** # ****   ******* # ****  * #",
"#   *** # ***********   ** # **   *********** # ***   #",
"#  ** # ***************    #    *************** # **  #",
"# @ # ******************** # ******************** # ! #",
"# # # # # # # # # # # # # # # # # # # # # # # # # # # #"};

int Gamespeed = 100;
int Level = 4;
int hp = x;
int maxhp = 5;
bool stopgame = false;

    cout << "Level : " << Level << endl;
    while(stopgame == false && Level == 4 && hp > 0)
    {
        cout << "Level : " << Level << endl;
        system("cls");
        for(int y = 0; y < 25; y++)
        {
            cout << Map[y] << endl;
        }





        cout << "Hp: " << hp << "/" << maxhp << endl;
        for(int y = 0; y < 25; y++)
        {
            for(int x = 0; x < 60 ; x++)
            {

                switch (Map[y][x])
                {
                    case '#':
                    {
                        Map [y][x] = 85;
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
                                    Level = 5;
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
                                    Level = 5;
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
                                    Level = 5;
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
                                    Level = 5;
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
    if(stopgame == false && Level == 5)
    {
        system("cls");
        int tet;
        cout << "##########################################" << endl;
        cout << "#              Excellent..               #" << endl;
        cout << "#                                        #" << endl;
        cout << "#     'Yesterday You Said TOMORROW'      #" << endl;
        cout << "#                                        #" << endl;
        cout << "#     1) Next Level        2) Exit       #" << endl;
        cout << "##########################################" << endl;
        if (tet == 2)
        {
            stopgame = true;
        }
        cout << "Level 5 goes Here...\n\n" << endl;
        level_10 l10;
        l10.lvl10(hp);
    }else if(hp < 0){
        cout << "Sorry.. You LOSE, Keep Trying";
        system("pause");
        return EXIT_SUCCESS;
    }


}


