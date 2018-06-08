#ifndef G2048_H
#define G2048_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef unsigned int uint;
enum movDir
{
    UP, DOWN, LEFT, RIGHT
};
struct tile
{
    tile() : val( 0 ), blocked( false ) {}
    uint val;
    bool blocked;
};

class g2048
{
public:
    g2048();
    void loop();
private:
    void drawBoard();
    void waitKey();
    void addTile();
    bool canMove();
    bool testAdd( int x, int y, uint v );
    void moveVert( int x, int y, int d );
    void moveHori( int x, int y, int d );
    void move( movDir d );
    tile board[4][4];
    bool win, done, moved;
    uint score;
};



#endif // G2048_H
