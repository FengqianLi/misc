#include <iostream>
#include <pthread.h>
#include <stdlib.h>

#define InterlockedIncrement(x) __sync_add_and_fetch(x, 1)

using namespace std;

int main(int argc, const char *argv[])
{
    int count = 0;
    cout << InterlockedIncrement(&count+1) << endl;
    cout << count << endl;

	return 0;
}
