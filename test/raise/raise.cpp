#include <iostream>
#include <csignal>

#define DebugBreak()    raise(SIGTRAP)

using namespace std;

    int
main( int argc, char **argv )
{
    cout << "hello world" << endl; 
    cout << SIGTRAP << endl;
    DebugBreak();
    //raise(SIGTRAP);
    return 0;
}
