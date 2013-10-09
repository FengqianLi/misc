#include <cstdio>
#include <iostream>

using namespace std;

    int
main( int argc, char **argv )
{
    FILE * pFile = fopen("test.txt", "r");
    setbuf(pFile, NULL);
    char buf[100];
    cout << "pos:" << ftell(pFile) << endl;
    fread(buf, sizeof(char), 5, pFile);
    cout << "pos:" << ftell(pFile) << endl;
    return 0;
}
