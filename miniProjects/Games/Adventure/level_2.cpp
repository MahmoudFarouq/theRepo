#include <iostream>
#include <windows.h>
#include "level_2.h"
#include "level_3.h"

using namespace std;
level_2::level_2()
{
    cout << "Level 2.. " << endl;
}
int level_2::lvl2(int x)
{
int w = 0;
int ww = 0;
int w1 = 0;
int w2 = 0;
int w3 = 0;
char Map[26][100] = {"#########################################################",
                    "##         *         ###############                *  ##",
                    "##  ##     ##        ###############        ##     ##  ##",
                    "##  ##     ##             #####             ##     ##  ##",
                    "##  ##     ######         #####         ######     ##  ##",
                    "##  ##     ######       * #####       * ######     ##  ##",
                    "##  ##         ##         #####         ##         ##  ##",
                    "##  ##         ##         #####         ##         ##  ##",
                    "##  ######                                    *######  ##",
                    "##  ######      #####      *       *#####      ######  ##",
                    "##  #           #####               #####           #  ##",
                    "##  ######      ##                     ##      ######  ##",
                    "##  ######      ##                     ##      ######  ##",
                    "##  ##          ############!############          ##  ##",
                    "##  ##          #########################          ##  ##",
                    "##  ##    ################     ################    ##  ##",
                    "##        #######                       #######        ##",
                    "## *##    #######                       #######    ##* ##",
                    "##  ##              ##             ##              ##  ##",
                    "##  ##              ##             ##              ##  ##",
                    "##  ##              ##             ##              ##  ##",
                    "##  ######     *######      *      ######    * ######  ##",
                    "##  ######     *######            *######    * ######  ##",
                    "##@                                                    ##",
                    "#########################################################"};

int Gamespeed = 100;
int Level = 2;
int hp = x;
int maxhp = 5;
bool stopgame = false;

    cout << "Level : " << Level << endl;
    while(stopgame == false && Level == 2 && hp > 0)

    {
        cout << "Level : " << Level << endl;
        system("cls");
        for(int y = 0; y < 26; y++)
        {
            cout << Map[y] << endl;
        }




        /*for(int x = 0 ; x < 20; x++)
        {
            switch (Map[4][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    switch (Map[4][x2])
                    {
                        case ' ':
                        {
                            if (w > 12)
                            {
                                w = 0;
                            }
                                if (w < 6)
                                {
                                    Map[4][x2] = '*';
                                    x2 -= 1;
                                    Map[4][x] = ' ';
                                    x -= 1;
                                    Map[4][x2] = ' ';
                                }
                                else if(w >= 6 && w < 12)
                                {
                                    Map[4][x2] = ' ';
                                    x2 += 2;
                                    Map[4][x] = ' ';
                                    x += 2;
                                    Map[4][x2] = '*';

                                }
                                w += 1;
                        }
                    }
                }
            }
        }*/






        cout << "Lives: " << hp << "/" << maxhp << endl;
        for(int y = 0; y < 26; y++)
        {
            for(int x = 0; x < 100 ; x++)
            {

                switch (Map[y][x])
                {
                    case '#':
                    {
                        Map [y][x] = 14;
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
                                    Level = 3;
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
                                    Level = 3;
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
                                    Level = 3;
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
                                    Level = 3;
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


/*____________________________________________________________________________________________________*/




        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[8][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[8][x2])
                    {
                        case ' ':
                        {
                            if (w > 70)
                            {
                                w = 0;
                            }
                                if (w < 35)
                                {
                                    Map[8][x2] = '*';
                                    x2 -= 1;
                                    if (Map[8][x2] != '@')
                                    {
                                    Map[8][x] = ' ';
                                    x -= 1;
                                    Map[8][x2] = ' ';
                                    }else{
                                    Map[8][x] = ' ';
                                    x -= 1;
                                    Map[8][x2] = '@';
                                    }
                                }
                                else if(w >= 35 && w < 70)
                                {
                                    if (Map[8][x3] != '@')
                                    {
                                    Map[8][x3] = ' ';
                                    x2 += 1;
                                    Map[8][x] = ' ';
                                    x += 1;
                                    Map[8][x3] = '*';
                                    }else{
                                    Map[8][x3] = ' ';
                                    x2 += 1;
                                    Map[8][x] = ' ';
                                    x += 1;
                                    Map[8][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w += 1;
                        }
                    }
                }
            }
        }





        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[5][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[5][x2])
                    {
                        case ' ':
                        {
                            if (w3 > 32)
                            {
                                w3 = 0;
                            }
                                if (w3 < 16)
                                {
                                    Map[5][x2] = '*';
                                    x2 -= 1;
                                    if (Map[5][x2] != '@')
                                    {
                                    Map[5][x] = ' ';
                                    x -= 1;
                                    Map[5][x2] = ' ';
                                    }else{
                                    Map[5][x] = ' ';
                                    x -= 1;
                                    Map[5][x2] = '@';
                                    }
                                }
                                else if(w3 >= 16 && w3 < 32)
                                {
                                    if (Map[5][x3] != '@')
                                    {
                                    Map[5][x3] = ' ';
                                    x2 += 1;
                                    Map[5][x] = ' ';
                                    x += 1;
                                    Map[5][x3] = '*';
                                    }else{
                                    Map[5][x3] = ' ';
                                    x2 += 1;
                                    Map[5][x] = ' ';
                                    x += 1;
                                    Map[5][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w3 += 1;
                        }
                    }
                }
            }
        }

        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[9][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[9][x2])
                    {
                        case ' ':
                        {
                            if (w3 > 32)
                            {
                                w3 = 0;
                            }
                                if (w3 < 16)
                                {
                                    Map[9][x2] = '*';
                                    x2 -= 1;
                                    if (Map[9][x2] != '@')
                                    {
                                    Map[9][x] = ' ';
                                    x -= 1;
                                    Map[9][x2] = ' ';
                                    }else{
                                    Map[9][x] = ' ';
                                    x -= 1;
                                    Map[9][x2] = '@';
                                    }
                                }
                                else if(w3 >= 16 && w3 < 32)
                                {
                                    if (Map[9][x3] != '@')
                                    {
                                    Map[9][x3] = ' ';
                                    x2 += 1;
                                    Map[9][x] = ' ';
                                    x += 1;
                                    Map[9][x3] = '*';
                                    }else{
                                    Map[9][x3] = ' ';
                                    x2 += 1;
                                    Map[9][x] = ' ';
                                    x += 1;
                                    Map[9][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w += 1;
                        }
                    }
                }
            }
        }






        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[21][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[21][x2])
                    {
                        case ' ':
                        {
                            if (w1 > 28)
                            {
                                w1 = 0;
                            }
                                if (w1 < 14)
                                {
                                    Map[21][x2] = '*';
                                    x2 -= 1;
                                    if (Map[21][x2] != '@')
                                    {
                                    Map[21][x] = ' ';
                                    x -= 1;
                                    Map[21][x2] = ' ';
                                    }else{
                                    Map[21][x] = ' ';
                                    x -= 1;
                                    Map[21][x2] = '@';
                                    }
                                }
                                else if(w1 >= 14 && w1 < 28)
                                {
                                    if (Map[21][x3] != '@')
                                    {
                                    Map[21][x3] = ' ';
                                    x2 += 1;
                                    Map[21][x] = ' ';
                                    x += 1;
                                    Map[21][x3] = '*';
                                    }else{
                                    Map[21][x3] = ' ';
                                    x2 += 1;
                                    Map[21][x] = ' ';
                                    x += 1;
                                    Map[21][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w1 += 1;
                        }
                    }
                }
            }
        }









        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[22][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[22][x2])
                    {
                        case ' ':
                        {
                            if (w2 > 28)
                            {
                                w2 = 0;
                            }
                                if (w2 < 14)
                                {
                                    Map[22][x2] = '*';
                                    x2 -= 1;
                                    if (Map[22][x2] != '@')
                                    {
                                    Map[22][x] = ' ';
                                    x -= 1;
                                    Map[22][x2] = ' ';
                                    }else{
                                    Map[22][x] = ' ';
                                    x -= 1;
                                    Map[22][x2] = '@';
                                    }
                                }
                                else if(w2 >= 14 && w2 < 28)
                                {
                                    if (Map[22][x3] != '@')
                                    {
                                    Map[22][x3] = ' ';
                                    x2 += 1;
                                    Map[22][x] = ' ';
                                    x += 1;
                                    Map[22][x3] = '*';
                                    }else{
                                    Map[22][x3] = ' ';
                                    x2 += 1;
                                    Map[22][x] = ' ';
                                    x += 1;
                                    Map[22][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w2 += 1;
                        }
                    }
                }
            }
        }


/*----------------------------------------------------------------------------------------------*/

        for(int y = 0 ; y < 26; y++)
        {
            switch (Map[y][3])
            {
                case '*':
                {
                    int y2 = y-1;
                    int y3 = y+1;
                    switch (Map[y2][3])
                    {
                        case ' ':
                        {
                            if (ww > 16)
                            {
                                ww = 0;
                            }
                                if (ww < 8)
                                {
                                    Map[y2][3] = '*';
                                    y2 -= 1;
                                    if (Map[y2][3] != '@')
                                    {
                                    Map[y][3] = ' ';
                                    y -= 1;
                                    Map[y2][3] = ' ';
                                    }else{
                                    Map[y][3] = ' ';
                                    y -= 1;
                                    Map[y2][3] = '@';
                                    }
                                }
                                else if(ww >= 8 && ww < 16)
                                {
                                    if (Map[y3][3] != '@')
                                    {
                                    Map[y3][3] = ' ';
                                    y2 += 1;
                                    Map[y][3] = ' ';
                                    y += 1;
                                    Map[y3][3] = '*';
                                    }else{
                                    Map[y3][3] = ' ';
                                    y2 += 1;
                                    Map[y][3] = ' ';
                                    y += 1;
                                    Map[y3][3] = '@';
                                    hp -= 1;
                                    }

                                }
                                ww += 1;
                        }
                    }
                }
            }
        }




        for(int y = 0 ; y < 26; y++)
        {
            switch (Map[y][53])
            {
                case '*':
                {
                    int y2 = y-1;
                    int y3 = y+1;
                    switch (Map[y2][53])
                    {
                        case ' ':
                        {
                            if (ww > 16)
                            {
                                ww = 0;
                            }
                                if (ww < 8)
                                {
                                    Map[y2][53] = '*';
                                    y2 -= 1;
                                    if (Map[y2][53] != '@')
                                    {
                                    Map[y][53] = ' ';
                                    y -= 1;
                                    Map[y2][53] = ' ';
                                    }else{
                                    Map[y][53] = ' ';
                                    y -= 1;
                                    Map[y2][53] = '@';
                                    }
                                }
                                else if(ww >= 8 && ww < 16)
                                {
                                    if (Map[y3][53] != '@')
                                    {
                                    Map[y3][53] = ' ';
                                    y2 += 1;
                                    Map[y][53] = ' ';
                                    y += 1;
                                    Map[y3][53] = '*';
                                    }else{
                                    Map[y3][53] = ' ';
                                    y2 += 1;
                                    Map[y][53] = ' ';
                                    y += 1;
                                    Map[y3][53] = '@';
                                    hp -= 1;
                                    }

                                }
                                ww += 1;
                        }
                    }
                }
            }
        }






        Sleep(Gamespeed);
    }
    if(stopgame == false && Level == 3 && hp > 0)
    {
        int tet;
        system("cls");
        cout << "##########################################" << endl;
        cout << "#              Excellent..               #" << endl;
        cout << "#                                        #" << endl;
        cout << "#        'You Arw What You READ'         #" << endl;
        cout << "#                                        #" << endl;
        cout << "#     1) Next Level        2) Exit       #" << endl;
        cout << "##########################################" << endl;
        if (tet == 2)
        {
            stopgame = true;
        }
        cout << "Level 3 goes Here...\n\n" << endl;
        level_3 l3;
        l3.lvl3(hp);
    }else if(hp < 0){
        cout << "Sorry.. You LOSE, Keep Trying";
        system("pause");
        return EXIT_SUCCESS;
    }
    return hp;
}
