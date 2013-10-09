#include <iostream>
#include "header.h"

using namespace std;

__forceinline void hello() {
    cout << "hello world!" << endl;
}

    int
main( int argc, char **argv )
{
    char * dir = "/home/damon/Workspace/test/a";
    if(CheckDirectoryExists(dir))
        cout << "dir exist!" << endl;
    else
        cout << "dir not exist!" << endl;
    return 0;
}
