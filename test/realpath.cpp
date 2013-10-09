#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;

int main()
{
	char resolved_path[100];
	cout << realpath("../../", resolved_path) << endl;
	//printf("\n%s\n", resolved_path);
	return 0;
}
