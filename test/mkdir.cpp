#include <iostream> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

//__forceinline void say_hello() {
always_inline void say_hello() {
    cout << "" << endl;
}

using namespace std;

int main(int argc, char **argv)
{
    say_hello();
    /*
    char * path= "/home/damon/Workspace/test/hello";
    struct stat st = { 0 };
    //if (stat(path, &st) == -1) {
    if(0 == mkdir(path, 0700))
        cout << "mkdir success!" << endl;
    else 
        cout << "mkdir failed!" << endl;
    //}
    //else
    //cout << "stat success!" << endl;
    */
    return 0;
}
