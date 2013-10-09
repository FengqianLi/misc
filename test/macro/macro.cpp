#include <iostream>
#include <stdio.h>
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);

#define Assert(x)                                                                      \
    do  {                                                                               \
        if (!(x)) {                                                                         \
            fprintf(stderr, "Assertion failed: [%d] in %s:%s@%d\n", x, __FILE__, __FUNCTION__, __LINE__); \
        } \
    }while(0)

#define Fatal(...)                                                                          \
    do                                                                                      \
{                                                                                       \
    fprintf(stderr, "FATAL! %s:%s:%d: ", __FUNCTION__, __FILE__, __LINE__);           \
    fprintf(stderr, __VA_ARGS__);                                                       \
    fflush(stderr);                                                                     \
}while(0)

#define myprintf(...) fprintf(stderr, "[lch]:File:%s, Line:%d, Function:%s,\n" \
                              __VA_ARGS__, __FILE__, __LINE__ ,__FUNCTION__);

int main(void)
{
	Assert(3);
	myprintf("hello world!");
	return 0;
}
