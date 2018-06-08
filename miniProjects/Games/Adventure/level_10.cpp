#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
#include "level_10.h"

level_10::level_10()
{
    cout << "Level 10.. " << endl;
}

int level_10::lvl10(int x)
{
int w = 0;
int w1 = 0;
int w2 = 0;
int w3 = 0;
int w4 = 0;
int w5 = 0;
int w6 = 0;
int w7 = 0;
int w8 = 0;
int w9 = 0;
int w10 = 0;
int w11 = 0;
int w12 = 0;
int w13 = 0;
int w14 = 0;
int w15 = 0;
char Map[40][100] = {"                                     $",
                    "                                  Mahmoud",
                    "                                   # ! #",
                    "                                  # * * #",
                    "                                 # ** ** #",
                    "                                # + * * + #",
                    "                               # ****** ** #",
                    "                              # -   * * * - #",
                    "                             # *** ********* #",
                    "                            # +  * * * * *  + #",
                    "                           # ************** ** #",
                    "                          # -           * * * - #",
                    "                         # **************** **** #",
                    "                        # +            * * * *  + #",
                    "                       # ********** ************** #",
                    "                      # -      * * * * *          - #",
                    "                     # ******* ********************* #",
                    "                    # +         * * * *             + #",
                    "                   # ** ****************************** #",
                    "                  # -       * * * * *                 - #",
                    "                 # # # # # # # # # # # # # # # # # # # # #",
                    "                # $ #            * * * * *            # $ #",
                    "               # *** # ***************************** # *** #",
                    "              # +   * * * * * * * * * * * * * * * * * *   + #",
                    "             # ******* # ************************* # ******* #",
                    "            # -       * * * * * * * * * * * * * * * *       - #",
                    "           # *********** # ********************* # *********** #",
                    "          # +           * * * * * * * * * * * * * *           + #",
                    "         # *************** # ***************** # *************** #",
                    "        # -               * * * * * * * * * * * *               - #",
                    "       # ******************* # ************* # ******************* #",
                    "      # +                   * * * * * * * * * *                   + #",
                    "     # *********************** # ********* # *********************** #",
                    "    # -                       * * * * * * * *                       - #",
                    "   # *************************** # ***** # *************************** #",
                    "  # +                          * * * * * * *                          + #",
                    " # * @ *************************** # * # ******************************* #",
                    "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #"};


int Gamespeed = 100;
int Level = 5;
int hp = x;
int maxhp = 5;
bool stopgame = false;

    cout << "Level : " << Level << endl;
    while(stopgame == false && Level == 5 && hp > 0)
    {
        cout << "Level : " << Level << endl;
        system("cls");
        for(int y = 0; y < 40; y++)
        {
            cout << Map[y] << endl;
        }





        cout << "Hp: " << hp << "/" << maxhp << endl;
        for(int y = 0; y < 40; y++)
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
                                    Level = 6;
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
                                    Level = 6;
                                }break;
                                case '*':
                                    {hp -=1;
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
                                    Level = 6;
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
                                    Level = 6;
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




        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[35][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[35][x2])
                    {
                        case ' ':
                        {
                            if (w > 65)
                            {
                                w = 0;
                            }
                                if (w < 33)
                                {
                                    Map[35][x2] = '*';
                                    x2 -= 1;
                                    if (Map[35][x2] != '@')
                                    {
                                    Map[35][x] = ' ';
                                    x -= 1;
                                    Map[35][x2] = ' ';
                                    }else{
                                    Map[35][x] = ' ';
                                    x -= 1;
                                    Map[35][x2] = '@';
                                    }
                                }
                                else if(w >= 33 && w < 65)
                                {
                                    if (Map[35][x3] != '@')
                                    {
                                    Map[35][x3] = ' ';
                                    x2 += 1;
                                    Map[35][x] = ' ';
                                    x += 1;
                                    Map[35][x3] = '*';
                                    }else{
                                    Map[35][x3] = ' ';
                                    x2 += 1;
                                    Map[35][x] = ' ';
                                    x += 1;
                                    Map[35][x3] = '@';
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
            switch (Map[33][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[33][x2])
                    {
                        case ' ':
                        {
                            if (w1 > 60)
                            {
                                w1 = 0;
                            }
                                if (w1 < 30)
                                {
                                    Map[33][x2] = '*';
                                    x2 -= 1;
                                    if (Map[33][x2] != '@')
                                    {
                                    Map[33][x] = ' ';
                                    x -= 1;
                                    Map[33][x2] = ' ';
                                    }else{
                                    Map[33][x] = ' ';
                                    x -= 1;
                                    Map[33][x2] = '@';
                                    }
                                }
                                else if(w1 >= 30 && w1 < 60)
                                {
                                    if (Map[33][x3] != '@')
                                    {
                                    Map[33][x3] = ' ';
                                    x2 += 1;
                                    Map[33][x] = ' ';
                                    x += 1;
                                    Map[33][x3] = '*';
                                    }else{
                                    Map[33][x3] = ' ';
                                    x2 += 1;
                                    Map[33][x] = ' ';
                                    x += 1;
                                    Map[33][x3] = '@';
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
            switch (Map[31][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[31][x2])
                    {
                        case ' ':
                        {
                            if (w2 > 65)
                            {
                                w2 = 0;
                            }
                                if (w2 < 33)
                                {
                                    Map[31][x2] = '*';
                                    x2 -= 1;
                                    if (Map[31][x2] != '@')
                                    {
                                    Map[31][x] = ' ';
                                    x -= 1;
                                    Map[31][x2] = ' ';
                                    }else{
                                    Map[31][x] = ' ';
                                    x -= 1;
                                    Map[31][x2] = '@';
                                    }
                                }
                                else if(w2 >= 33 && w2 < 65)
                                {
                                    if (Map[31][x3] != '@')
                                    {
                                    Map[31][x3] = ' ';
                                    x2 += 1;
                                    Map[31][x] = ' ';
                                    x += 1;
                                    Map[31][x3] = '*';
                                    }else{
                                    Map[31][x3] = ' ';
                                    x2 += 1;
                                    Map[31][x] = ' ';
                                    x += 1;
                                    Map[31][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w2 += 1;
                        }
                    }
                }
            }
        }




        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[29][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[29][x2])
                    {
                        case ' ':
                        {
                            if (w3 > 65)
                            {
                                w3 = 0;
                            }
                                if (w3 < 33)
                                {
                                    Map[29][x2] = '*';
                                    x2 -= 1;
                                    if (Map[29][x2] != '@')
                                    {
                                    Map[29][x] = ' ';
                                    x -= 1;
                                    Map[29][x2] = ' ';
                                    }else{
                                    Map[29][x] = ' ';
                                    x -= 1;
                                    Map[29][x2] = '@';
                                    }
                                }
                                else if(w3 >= 33 && w3 < 65)
                                {
                                    if (Map[29][x3] != '@')
                                    {
                                    Map[29][x3] = ' ';
                                    x2 += 1;
                                    Map[29][x] = ' ';
                                    x += 1;
                                    Map[29][x3] = '*';
                                    }else{
                                    Map[29][x3] = ' ';
                                    x2 += 1;
                                    Map[29][x] = ' ';
                                    x += 1;
                                    Map[29][x3] = '@';
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
            switch (Map[27][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[27][x2])
                    {
                        case ' ':
                        {
                            if (w4 > 65)
                            {
                                w4 = 0;
                            }
                                if (w4 < 33)
                                {
                                    Map[27][x2] = '*';
                                    x2 -= 1;
                                    if (Map[27][x2] != '@')
                                    {
                                    Map[27][x] = ' ';
                                    x -= 1;
                                    Map[27][x2] = ' ';
                                    }else{
                                    Map[27][x] = ' ';
                                    x -= 1;
                                    Map[27][x2] = '@';
                                    }
                                }
                                else if(w4 >= 33 && w4 < 65)
                                {
                                    if (Map[27][x3] != '@')
                                    {
                                    Map[27][x3] = ' ';
                                    x2 += 1;
                                    Map[27][x] = ' ';
                                    x += 1;
                                    Map[27][x3] = '*';
                                    }else{
                                    Map[27][x3] = ' ';
                                    x2 += 1;
                                    Map[27][x] = ' ';
                                    x += 1;
                                    Map[27][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w4 += 1;
                        }
                    }
                }
            }
        }





     for(int x = 0 ; x < 100; x++)
        {
            switch (Map[25][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[25][x2])
                    {
                        case ' ':
                        {
                            if (w5 > 65)
                            {
                                w5 = 0;
                            }
                                if (w5 < 33)
                                {
                                    Map[25][x2] = '*';
                                    x2 -= 1;
                                    if (Map[25][x2] != '@')
                                    {
                                    Map[25][x] = ' ';
                                    x -= 1;
                                    Map[25][x2] = ' ';
                                    }else{
                                    Map[25][x] = ' ';
                                    x -= 1;
                                    Map[25][x2] = '@';
                                    }
                                }
                                else if(w5 >= 33 && w5 < 65)
                                {
                                    if (Map[25][x3] != '@')
                                    {
                                    Map[25][x3] = ' ';
                                    x2 += 1;
                                    Map[25][x] = ' ';
                                    x += 1;
                                    Map[25][x3] = '*';
                                    }else{
                                    Map[25][x3] = ' ';
                                    x2 += 1;
                                    Map[25][x] = ' ';
                                    x += 1;
                                    Map[25][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w5 += 1;
                        }
                    }
                }
            }
        }






        for(int x = 0 ; x < 100; x++)
        {
            switch (Map[23][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[23][x2])
                    {
                        case ' ':
                        {
                            if (w6 > 65)
                            {
                                w6 = 0;
                            }
                                if (w6 < 33)
                                {
                                    Map[23][x2] = '*';
                                    x2 -= 1;
                                    if (Map[23][x2] != '@')
                                    {
                                    Map[23][x] = ' ';
                                    x -= 1;
                                    Map[23][x2] = ' ';
                                    }else{
                                    Map[23][x] = ' ';
                                    x -= 1;
                                    Map[23][x2] = '@';
                                    }
                                }
                                else if(w6 >= 33 && w6 < 65)
                                {
                                    if (Map[23][x3] != '@')
                                    {
                                    Map[23][x3] = ' ';
                                    x2 += 1;
                                    Map[23][x] = ' ';
                                    x += 1;
                                    Map[23][x3] = '*';
                                    }else{
                                    Map[23][x3] = ' ';
                                    x2 += 1;
                                    Map[23][x] = ' ';
                                    x += 1;
                                    Map[23][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w6 += 1;
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
                            if (w7 > 65)
                            {
                                w7 = 0;
                            }
                                if (w7 < 33)
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
                                else if(w7 >= 33 && w7 < 65)
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
                                w7 += 1;
                        }
                    }
                }
            }
        }






                for(int x = 0 ; x < 100; x++)
        {
            switch (Map[19][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[19][x2])
                    {
                        case ' ':
                        {
                            if (w8 > 65)
                            {
                                w8 = 0;
                            }
                                if (w8 < 33)
                                {
                                    Map[19][x2] = '*';
                                    x2 -= 1;
                                    if (Map[19][x2] != '@')
                                    {
                                    Map[19][x] = ' ';
                                    x -= 1;
                                    Map[19][x2] = ' ';
                                    }else{
                                    Map[19][x] = ' ';
                                    x -= 1;
                                    Map[19][x2] = '@';
                                    }
                                }
                                else if(w8 >= 33 && w8 < 65)
                                {
                                    if (Map[19][x3] != '@')
                                    {
                                    Map[19][x3] = ' ';
                                    x2 += 1;
                                    Map[19][x] = ' ';
                                    x += 1;
                                    Map[19][x3] = '*';
                                    }else{
                                    Map[19][x3] = ' ';
                                    x2 += 1;
                                    Map[19][x] = ' ';
                                    x += 1;
                                    Map[19][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w8 += 1;
                        }
                    }
                }
            }
        }








                for(int x = 0 ; x < 100; x++)
        {
            switch (Map[17][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[17][x2])
                    {
                        case ' ':
                        {
                            if (w9 > 65)
                            {
                                w9 = 0;
                            }
                                if (w9 < 33)
                                {
                                    Map[17][x2] = '*';
                                    x2 -= 1;
                                    if (Map[17][x2] != '@')
                                    {
                                    Map[17][x] = ' ';
                                    x -= 1;
                                    Map[17][x2] = ' ';
                                    }else{
                                    Map[17][x] = ' ';
                                    x -= 1;
                                    Map[17][x2] = '@';
                                    }
                                }
                                else if(w9 >= 33 && w9 < 65)
                                {
                                    if (Map[17][x3] != '@')
                                    {
                                    Map[17][x3] = ' ';
                                    x2 += 1;
                                    Map[17][x] = ' ';
                                    x += 1;
                                    Map[17][x3] = '*';
                                    }else{
                                    Map[17][x3] = ' ';
                                    x2 += 1;
                                    Map[17][x] = ' ';
                                    x += 1;
                                    Map[17][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w9 += 1;
                        }
                    }
                }
            }
        }







                for(int x = 0 ; x < 100; x++)
        {
            switch (Map[15][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[15][x2])
                    {
                        case ' ':
                        {
                            if (w10 > 65)
                            {
                                w10 = 0;
                            }
                                if (w10 < 33)
                                {
                                    Map[15][x2] = '*';
                                    x2 -= 1;
                                    if (Map[15][x2] != '@')
                                    {
                                    Map[15][x] = ' ';
                                    x -= 1;
                                    Map[15][x2] = ' ';
                                    }else{
                                    Map[15][x] = ' ';
                                    x -= 1;
                                    Map[15][x2] = '@';
                                    }
                                }
                                else if(w10 >= 33 && w10 < 65)
                                {
                                    if (Map[15][x3] != '@')
                                    {
                                    Map[15][x3] = ' ';
                                    x2 += 1;
                                    Map[15][x] = ' ';
                                    x += 1;
                                    Map[15][x3] = '*';
                                    }else{
                                    Map[15][x3] = ' ';
                                    x2 += 1;
                                    Map[15][x] = ' ';
                                    x += 1;
                                    Map[15][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w10 += 1;
                        }
                    }
                }
            }
        }






                for(int x = 0 ; x < 100; x++)
        {
            switch (Map[13][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[13][x2])
                    {
                        case ' ':
                        {
                            if (w11 > 65)
                            {
                                w11 = 0;
                            }
                                if (w11 < 33)
                                {
                                    Map[13][x2] = '*';
                                    x2 -= 1;
                                    if (Map[13][x2] != '@')
                                    {
                                    Map[13][x] = ' ';
                                    x -= 1;
                                    Map[13][x2] = ' ';
                                    }else{
                                    Map[13][x] = ' ';
                                    x -= 1;
                                    Map[13][x2] = '@';
                                    }
                                }
                                else if(w11 >= 33 && w11 < 65)
                                {
                                    if (Map[13][x3] != '@')
                                    {
                                    Map[13][x3] = ' ';
                                    x2 += 1;
                                    Map[13][x] = ' ';
                                    x += 1;
                                    Map[13][x3] = '*';
                                    }else{
                                    Map[13][x3] = ' ';
                                    x2 += 1;
                                    Map[13][x] = ' ';
                                    x += 1;
                                    Map[13][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w11 += 1;
                        }
                    }
                }
            }
        }







                for(int x = 0 ; x < 100; x++)
        {
            switch (Map[11][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[11][x2])
                    {
                        case ' ':
                        {
                            if (w12 > 65)
                            {
                                w12 = 0;
                            }
                                if (w12 < 33)
                                {
                                    Map[11][x2] = '*';
                                    x2 -= 1;
                                    if (Map[11][x2] != '@')
                                    {
                                    Map[11][x] = ' ';
                                    x -= 1;
                                    Map[11][x2] = ' ';
                                    }else{
                                    Map[11][x] = ' ';
                                    x -= 1;
                                    Map[11][x2] = '@';
                                    }
                                }
                                else if(w12 >= 33 && w12 < 65)
                                {
                                    if (Map[11][x3] != '@')
                                    {
                                    Map[11][x3] = ' ';
                                    x2 += 1;
                                    Map[11][x] = ' ';
                                    x += 1;
                                    Map[11][x3] = '*';
                                    }else{
                                    Map[11][x3] = ' ';
                                    x2 += 1;
                                    Map[11][x] = ' ';
                                    x += 1;
                                    Map[11][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w12 += 1;
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
                            if (w13 > 65)
                            {
                                w13 = 0;
                            }
                                if (w13 < 33)
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
                                else if(w13 >= 33 && w13 < 65)
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
                                w13 += 1;
                        }
                    }
                }
            }
        }






                for(int x = 0 ; x < 100; x++)
        {
            switch (Map[7][x])
            {
                case '*':
                {
                    int x2 = x-1;
                    int x3 = x+1;
                    switch (Map[7][x2])
                    {
                        case ' ':
                        {
                            if (w14 > 65)
                            {
                                w14 = 0;
                            }
                                if (w14 < 33)
                                {
                                    Map[7][x2] = '*';
                                    x2 -= 1;
                                    if (Map[7][x2] != '@')
                                    {
                                    Map[7][x] = ' ';
                                    x -= 1;
                                    Map[7][x2] = ' ';
                                    }else{
                                    Map[7][x] = ' ';
                                    x -= 1;
                                    Map[7][x2] = '@';
                                    }
                                }
                                else if(w14 >= 33 && w14 < 65)
                                {
                                    if (Map[7][x3] != '@')
                                    {
                                    Map[7][x3] = ' ';
                                    x2 += 1;
                                    Map[7][x] = ' ';
                                    x += 1;
                                    Map[7][x3] = '*';
                                    }else{
                                    Map[7][x3] = ' ';
                                    x2 += 1;
                                    Map[7][x] = ' ';
                                    x += 1;
                                    Map[7][x3] = '@';
                                    hp -= 1;
                                    }

                                }
                                w14 += 1;
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
                            if (w15 > 65)
                            {
                                w15 = 0;
                            }
                                if (w15 < 33)
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
                                else if(w15 >= 33 && w15 < 65)
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
                                w15 += 1;
                        }
                    }
                }
            }
        }





        Sleep(Gamespeed);
    }
    if(hp < 0)
    {

        cout << "Sorry.. You LOSE, Keep Trying";
        system("pause");
        return EXIT_SUCCESS;
    }


}

