#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

class Map
{
    public:
        char GameMap[20][50] = {"################################################",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "#                                              #",
                                "################################################"};
        Map(){}
        void PrintMap()
        {
            for(int i = 0; i < 20; i++)
            {
                for(int j = 0; j < 50; j++)
                {
                    cout << GameMap[i][j];
                }
                cout << endl;
            }
        }
        ~Map(){}
};
struct Point{int x; int y;};

class Step
{
public:
    Step(char s, Step *h, Step *t = NULL)
    {
        Boss = h;
        Tail = t;
        p.x = h->p.x;
        p.y = h->p.y;
        sym = s;
    }
    Step(int x, int y, char s)
    {
        p.x = x;
        p.y = y;
        sym = s;
        Boss = NULL;
        Tail = NULL;
    }
    ~Step(){}
    Step *Boss;
    Step *Tail;
    Point p;
    char sym;
    void Move()
    {
        if(Tail != NULL) Tail->Move();
        p.x = Boss->p.x;
        p.y = Boss->p.y;
    }
};

char dir = 'u';
Map m;
Step* *snake;
int size = 5;
int speed = 200;
void MoveSnake();
void SetAll();
void eat();
void gameOver();
int main()
{
    srand(time(0));
    m.GameMap[10][10] = '*';
    m.PrintMap();
    SetAll();
    while(true)
    {
        MoveSnake();
        if(GetAsyncKeyState(VK_UP) != 0 && dir != 'd')   {dir = 'u';}
        else if(GetAsyncKeyState(VK_DOWN) != 0 && dir != 'u') {dir = 'd';}
        else if(GetAsyncKeyState(VK_RIGHT) != 0 && dir != 'l'){dir = 'r';}
        else if(GetAsyncKeyState(VK_LEFT) != 0 && dir != 'r') {dir = 'l';}
        Sleep(speed);
    }
    return 0;
}
void eat()
{
    snake[size] = new Step('1', snake[size-1]);
    snake[size-1]->Tail = snake[size];
    size++;
}
void gameOver()
{
    cout << "You Lose" << endl;
    cout << "Score: " << size - 5<< endl;
    system("Pause");
    exit(1);
}
void createFood()
{
    int x = rand()%20;
    int y = rand()%50;
    switch(m.GameMap[x][y])
    {
        case ' ':
            m.GameMap[x][y] = '*';
            return;
    }
    createFood();
}
void SetAll()
{
    snake = new Step*[100];
    snake[0] = new Step(10, 25, '0');
    for(int i = 1; i < size; i++)
    {
        snake[i] = new Step('1', snake[i-1]);
    }
    for(int i = 0; i < size-1; i++)
    {
        snake[i]->Tail = snake[i+1];
    }
}
void MoveSnake()
{
    for(int i = 0; i < size; i++)
    {
        Point p = snake[i]->p;
        m.GameMap[p.x][p.y] = ' ';
    }
    snake[1]->Move();
    if(dir == 'u'){snake[0]->p.x--;}
    if(dir == 'd'){snake[0]->p.x++;}
    if(dir == 'r'){snake[0]->p.y++;}
    if(dir == 'l'){snake[0]->p.y--;}
    switch(m.GameMap[snake[0]->p.x][snake[0]->p.y])
    {
        case '#':
        case '1':
            gameOver();
            break;
        case '*':
            eat();
            createFood();
            break;
    }
    for(int i = 0; i < size; i++)
    {
        Point p = snake[i]->p;
        m.GameMap[p.x][p.y] = snake[i]->sym;
    }
    switch(m.GameMap[snake[0]->p.x][snake[0]->p.y])
    {
        case '1':
            gameOver();
            break;
    }
    system("cls");
    cout << "Score: " << size - 5 << endl;
    m.PrintMap();
}

