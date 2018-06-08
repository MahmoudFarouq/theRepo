#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char **panner;

void letter(string ltr, int b)
{
    if(b == 0){
        strcpy(panner[0], ltr.substr(0, 10).c_str());
        strcpy(panner[1], ltr.substr(10, 10).c_str());
        strcpy(panner[2], ltr.substr(20, 10).c_str());
        strcpy(panner[3], ltr.substr(30, 10).c_str());
        strcpy(panner[4], ltr.substr(40, 10).c_str());
    }else{
        strcat(panner[0], ltr.substr(0, 10).c_str());
        strcat(panner[1], ltr.substr(10, 10).c_str());
        strcat(panner[2], ltr.substr(20, 10).c_str());
        strcat(panner[3], ltr.substr(30, 10).c_str());
        strcat(panner[4], ltr.substr(40, 10).c_str());
    }
}


int main()
{
    string name;
    cout<<"Enter your name Please:-"<<endl<<endl;
    cout<<"______________________________________"<<endl<<endl;
    getline(cin, name);
    cout<<"______________________________________"<<endl<<endl;

    int width = name.length()*10;
    int height = 5;
    panner = new char*[ height ];
    for(int i = 0; i < height; i++){
        panner[i] = new char[width];
	}

    for(unsigned d=0;d < name.length();d++)
    {
        switch(name[d]){

        case 'a':
        case 'A':
        letter("..######....#....#....######....#....#....#....#..", d);
        break;

        case 'b':
        case 'B':
        letter("..######....#....#....#####.....#....#....######..", d);
        break;

        case 'c':
        case 'C':
        letter("..######....#.........#.........#.........######..", d);
        break;

        case 'd':
        case 'D':
        letter("..#####.....#....#....#....#....#....#....#####...", d);
        break;

        case 'e':
        case 'E':
        letter("..######....#.........#####.....#.........######..", d);
        break;

        case 'f':
        case 'F':
        letter("..######....#.........#####.....#.........#.......", d);
        break;

        case 'g':
        case 'G':
        letter("..######....#.........#####.....#....#....#####...", d);
        break;


        case 'h':
        case 'H':
        letter("..#....#....#....#....######....#....#....#....#..", d);
        break;

        case 'i':
        case 'I':
        letter("..######......##........##........##......######..", d);
        break;

        case 'j':
        case 'J':
        letter("..######......##........##......#.##......####....", d);
        break;

        case 'k':
        case 'K':
        letter("..#...#.....#..#......##........#..#......#...#...", d);
        break;

        case 'l':
        case 'L':
        letter("..#.........#.........#.........#.........######..", d);
        break;

        case 'm':
        case 'M':
        letter("..#....#....##..##....#.##.#....#....#....#....#..", d);
        break;

        case 'n':
        case 'N':
        letter("..#....#....##...#....#.#..#....#..#.#....#...##..", d);
        break;

        case 'o':
        case 'O':
        letter("..######....#....#....#....#....#....#....######..", d);
        break;

        case 'p':
        case 'P':
        letter("..######....#....#....######....#.........#.......", d);
        break;

        case 'q':
        case 'Q':
        letter("..######....#....#....#.#..#....#..#.#....######..", d);
        break;

        case 'r':
        case 'R':
        letter("..######....#....#....#.##.....#...#.....#....#..", d);
        break;

        case 's':
        case 'S':
        letter("..######....#.........######.........#....######..", d);
        break;

        case 't':
        case 'T':
        letter("..######......##........##........##........##....", d);
        break;

        case 'u':
        case 'U':
        letter("..#....#....#....#....#....#....#....#....######..", d);
        break;

        case 'v':
        case 'V':
        letter("..#....#....#....#....#....#.....#..#.......##....", d);
        break;


        case 'w':
        case 'W':
        letter("..#....#....#....#....#.##.#....##..##....#....#..", d);
        break;

        case 'x':
        case 'X':
        letter("..#....#.....#..#.......##.......#..#.....#....#..", d);
        break;

        case 'y':
        case 'Y':
        letter("..#....#.....#..#.......##........##........##....", d);
        break;

        case 'z':
        case 'Z':
        letter("..######........#........#........#.......######..", d);
        break;

        case ' ':
        letter("..................................................", d);
        break;
        }

    }

    for(int i = 0; i < 5; i++){
        cout << panner[i];
        cout << endl;
    }

	for(int i = 0; i < 5; i++){
        delete[] panner[i];
    }
    delete[] panner;

    cout<<"______________________________________"<<endl<<endl;
    cout<<"If you like it!!! Please hit one like."<<endl;
    cout<<"______________________________________"<<endl<<endl;
}
