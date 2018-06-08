#include <iostream>
using namespace std;
char player, CPU;
void check(int x, int y);
char map[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
int main()
{
    int x,y, counter =0;
    char winner;
    cout << "Hi!, This is TIC TAC TOE Game" << endl;
    cout << "which symbol you would like to take?! (X,O)" << endl;
    cin >> player;
    if (player == 'x' || player == 'X') {CPU = 'O';player = 'X';}
    else if (player == 'o' || player == 'O') {CPU = 'X';player = 'O';}
    else{cout << "i will take it as you are 'X'." << endl; player = 'X'; CPU = 'O';}
    while(true)
    {
        if (map[0][0] == map[0][1] && map[0][1]== map[0][2]&&map[0][2] != ' '){winner = map[0][0]; break;}
        if (map[1][0] == map[1][1] && map[1][1]== map[1][2]&&map[1][2] != ' '){winner = map[1][0]; break;}
        if (map[2][0] == map[2][1] && map[2][1]== map[2][2]&&map[2][2] != ' '){winner = map[2][0]; break;}
        if (map[0][0] == map[1][0] && map[1][0]== map[2][0]&&map[2][0] != ' '){winner = map[0][0]; break;}
        if (map[0][1] == map[1][1] && map[1][1]== map[2][1]&&map[2][1] != ' '){winner = map[0][1]; break;}
        if (map[0][2] == map[1][2] && map[1][2]== map[2][2]&&map[2][2] != ' '){winner = map[0][2]; break;}
        if (map[0][0] == map[1][1] && map[1][1]== map[2][2]&&map[2][2] != ' '){winner = map[0][0]; break;}
        if (map[0][2] == map[1][1] && map[1][1]== map[2][0]&&map[2][0] != ' '){winner = map[0][2]; break;}
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                if (map[i][j] != ' '){counter++;}
                else    {counter =0;break;}
            }
        if (counter == 9) break;
        system("clear");
        if (player == 'X') map[1][1] = 'O';
        cout << "       1       2       3    " << endl;
        cout << "   #########################" << endl;
        cout << "   #       #       #       #" << endl;
        cout << " 1 #   "<< map[0][0] << "   #   "<< map[0][1] << "   #   "<< map[0][2] << "   #" << endl;
        cout << "   #       #       #       #" << endl;
        cout << "   #########################" << endl;
        cout << "   #       #       #       #" << endl;
        cout << " 2 #   "<< map[1][0] << "   #   "<< map[1][1] << "   #   "<< map[1][2] << "   #" << endl;
        cout << "   #       #       #       #" << endl;
        cout << "   #########################" << endl;
        cout << "   #       #       #       #" << endl;
        cout << " 3 #   "<< map[2][0] << "   #   "<< map[2][1] << "   #   "<< map[2][2] << "   #" << endl;
        cout << "   #       #       #       #" << endl;
        cout << "   #########################\n" << endl;
        cout << "your turn.." << endl;
        cin >> x >> y;
        while (map[x-1][y-1] != ' ')  {cin >> x >> y;}
        map[x-1][y-1] = player;
        check(x-1, y-1);
    }
    if(winner == CPU){cout << "CPU Wins!" << endl;cout << "sorry you lose, try again.." << endl;}
    else if (winner == player)  {cout << "Wow!!.. You win :)" << endl;}
    else if(counter == 9) {cout << "Draw!.." << endl;}
}
void check(int x, int y)
{
    bool bolla = true;
    if(x == 1 && y == 1){
    if (map[x][y+1] == map[x][y] && map[x][y-1] == ' ') map[x][y-1] = CPU;
    else if (map[x][y-1] == map[x][y] && map[x][y+1] == ' ') map[x][y+1] = CPU;
    else if (map[x+1][y] == map[x][y] && map[x-1][y] == ' ') map[x-1][y] = CPU;
    else if (map[x-1][y] == map[x][y] && map[x+1][y] == ' ') map[x+1][y] = CPU;
    else if (map[x-1][y+1] == map[x][y] && map[x+1][y-1] == ' ') map[x+1][y-1] = CPU;
    else if (map[x+1][y-1] == map[x][y] && map[x-1][y+1] == ' ') map[x-1][y+1] = CPU;
    else if (map[x-1][y-1] == map[x][y] && map[x+1][y+1] == ' ') map[x+1][y+1] = CPU;
    else if (map[x+1][y+1] == map[x][y] && map[x-1][y-1] == ' ') map[x-1][y-1] = CPU;
    else bolla = false;}
    if( x == 2 && y == 1){
    if (map[x][y-1] == map[x][y] && map[x][y+1] == ' ') map[x][y+1] = CPU;
    else if (map[x][y+1] == map[x][y] && map[x][y-1] == ' ') map[x][y-1] = CPU;
    else if (map[x-1][y] == map[x][y] && map[x-2][y] == ' ') map[x-2][y] = CPU;
    else if (map[x-2][y] == map[x][y] && map[x-1][y] == ' ') map[x-1][y] = CPU;
    else bolla = false;}
    if(x == 1 && y == 0){
    if (map[x-1][y] == map[x][y] && map[x+1][y] == ' ') map[x+1][y] = CPU;
    else if (map[x+1][y] == map[x][y] && map[x-1][y] == ' ') map[x-1][y] = CPU;
    else if (map[x][y+1] == map[x][y] && map[x][y+2] == ' ') map[x][y+2] = CPU;
    else if (map[x][y+2] == map[x][y] && map[x][y+1] == ' ') map[x][y+1] = CPU;
    else bolla = false;}
    if(x == 1 && y == 2){
    if (map[x-1][y] == map[x][y] && map[x+1][y] == ' ') map[x+1][y] = CPU;
    else if (map[x+1][y] == map[x][y] && map[x-1][y] == ' ') map[x-1][y] = CPU;
    else if (map[x][y-1] == map[x][y] && map[x][y-2] == ' ') map[x][y-2] = CPU;
    else if (map[x][y-2] == map[x][y] && map[x][y-1] == ' ') map[x][y-1] = CPU;
    else bolla = false;}
    if(x == 0 && y == 1){
    if (map[x][y-1] == map[x][y] && map[x][y+1] == ' ') map[x][y+1] = CPU;
    else if (map[x][y+1] == map[x][y] && map[x][y-1] == ' ') map[x][y-1] = CPU;
    else if (map[x+1][y] == map[x][y] && map[x+2][y] == ' ') map[x+2][y] = CPU;
    else if (map[x+2][y] == map[x][y] && map[x+1][y] == ' ') map[x+1][y] = CPU;
    else bolla = false;}
    if (x == 0 && y == 0){
    if(map[x+1][y+1] == map[x][y] && map[x+2][y+2] == ' ') map[x+2][y+2] = CPU;
    else if(map[x+2][y+2] == map[x][y] && map[x+1][y+1] == ' ') map[x+1][y+1] = CPU;
    else if(map[x][y+1] == map[x][y] && map[x][y+2] == ' ') map[x][y+2] = CPU;
    else if(map[x][y+2] == map[x][y] && map[x][y+1] == ' ') map[x][y+1] = CPU;
    else if(map[x+1][y] == map[x][y] && map[x+2][y] == ' ') map[x+2][y] = CPU;
    else if(map[x+2][y] == map[x][y] && map[x+1][y] == ' ') map[x+1][y] = CPU;
    else bolla = false;}
    if (x == 2 && y == 0){
    if(map[x-1][y+1] == map[x][y] && map[x-2][y+2] == ' ') map[x-2][y+2] = CPU;
    else if(map[x-2][y+2] == map[x][y]&& map[x-1][y+1] == ' ') map[x-1][y+1] = CPU;
    else if(map[x][y+1] == map[x][y]&& map[x][y+2] == ' ') map[x][y+2] = CPU;
    else if(map[x][y+2] == map[x][y]&& map[x][y+1] == ' ') map[x][y+1] = CPU;
    else if(map[x-1][y] == map[x][y]&& map[x-2][y] == ' ') map[x-2][y] = CPU;
    else if(map[x-2][y] == map[x][y]&& map[x-1][y] == ' ') map[x-1][y] = CPU;
    else bolla = false;}
    if (x == 0 && y == 2){
    if(map[x+1][y-1] == map[x][y]&& map[x+2][y-2] == ' ') map[x+2][y-2] = CPU;
    else if(map[x+2][y-2] == map[x][y]&& map[x+1][y-1] == ' ') map[x+1][y-1] = CPU;
    else if(map[x][y-1] == map[x][y]&& map[x][y-2] == ' ') map[x][y-2] = CPU;
    else if(map[x][y-2] == map[x][y]&& map[x][y-1] == ' ') map[x][y-1] = CPU;
    else if(map[x+1][y] == map[x][y]&& map[x+2][y] == ' ') map[x+2][y] = CPU;
    else if(map[x+2][y] == map[x][y]&& map[x+1][y] == ' ') map[x+1][y] = CPU;
    else bolla = false;}
    if (x == 2 && y == 2){
    if(map[x-1][y-1] == map[x][y]&& map[x-2][y-2] == ' ') map[x-2][y-2] = CPU;
    else if(map[x-2][y-2] == map[x][y]&& map[x-1][y-1] == ' ') map[x-1][y-1] = CPU;
    else if(map[x][y-1] == map[x][y]&& map[x][y-2] == ' ') map[x][y-2] = CPU;
    else if(map[x][y-2] == map[x][y]&& map[x][y-1] == ' ') map[x][y-1] = CPU;
    else if(map[x-1][y] == map[x][y]&& map[x-2][y] == ' ') map[x-2][y] = CPU;
    else if(map[x-2][y] == map[x][y]&& map[x-1][y] == ' ') map[x-1][y] = CPU;
    else bolla = false;}
    if(bolla == false){
             if (map[1][1] == ' ') map[1][1] = CPU;
        else if (map[0][0] == ' ') map[0][0] = CPU;
        else if (map[0][2] == ' ') map[0][2] = CPU;
        else if (map[0][1] == ' ') map[0][1] = CPU;
        else if (map[2][2] == ' ') map[2][2] = CPU;
        else if (map[2][0] == ' ') map[2][0] = CPU;
        else if (map[2][1] == ' ') map[2][1] = CPU;
        else if (map[1][0] == ' ') map[1][0] = CPU;
        else if (map[1][2] == ' ') map[1][2] = CPU;
        bolla = true;}
}
