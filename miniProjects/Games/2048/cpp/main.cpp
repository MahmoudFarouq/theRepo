#include <time.h>
#include <g2048.h>


int main( int argc, char* argv[] )
{
    srand( static_cast<uint>( time( NULL ) ) );
    g2048 g;
    g.loop();
    return system( "pause" );
}
