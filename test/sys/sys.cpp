#include <iostream>
#include <sys/sysinfo.h>

using namespace std;

int main(int argc, char **argv)
{
	struct sysinfo info;
	sysinfo(&info);
	cout << (size_t) info.totalram * (size_t) info.mem_unit << endl;
	cout << (size_t) info.freeram * (size_t) info.mem_unit << endl;
	cout << (size_t) info.totalram << endl;;
}
