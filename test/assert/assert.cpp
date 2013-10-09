#include <iostream>
#include <cstdio>
#include <csignal>

using namespace std;

#define DebugBreak()    raise(SIGTRAP)
#define Assert(x)                                                                      \
    do  {                                                                               \
        if (!(x)) {                                                                         \
            fprintf(stderr, "Assertion failed: [%s] in %s:%s@%d\n", x, __FILE__, __FUNCTION__, __LINE__); \
            DebugBreak();                                                                      \
        }                                                                                                   \
    } while (0)

    int
main( int argc, char **argv )
{
    int num = -1;
    Assert(num >= 0);
    return 0;
}
