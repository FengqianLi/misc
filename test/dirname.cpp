#include <iostream>
#include <libgen.h>

using namespace std;

    int
main( int argc, char **argv )
{
    char * file = "/lib/hello/";
    cout << dirname(file) << endl;
    return 0;
}
