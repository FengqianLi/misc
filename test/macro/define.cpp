#include <iostream> 

using namespace std;

#define my_first_inc(x, y) my_second_inc(y, x)

int my_second_inc(int num1, int num2)
{
	return num1 + num2;
}

int main(int argc, char **argv)
{
	int num1 = 1, num2 = 2;
	cout << my_first_inc(num1, num2) << endl;
	return 0;
}
