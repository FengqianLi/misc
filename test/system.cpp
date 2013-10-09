#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

    int
main( int argc, char **argv )
{
    char str[100];
    string dir;
    cin >> dir;
    //strcat(str, dir.c_str());
    sprintf(str, "rm -rf %s", dir.c_str());
    cout << "command: " << str << endl;
    system(str);
    return 0;
}
