#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	struct stat buf;
	stat("/etc/hosts", &buf);
    cout << S_ISREG(buf.st_mode) << endl;
    cout << S_ISDIR(buf.st_mode) << endl;
}
