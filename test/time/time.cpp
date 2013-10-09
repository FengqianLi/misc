#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

int main(int argc, char **argv)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

    long my_second, diff_second = 365*24*3600*30;
    my_second = tv.tv_sec;
    my_second -= diff_second;
    cout << diff_second << endl;
    cout << my_second << ":" << tv.tv_usec << endl;
	///int time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;	// convert tv_sec & tv_usec to millisecond
    //cout << time_in_mill << endl;
	/*
	   struct timespec res1, res2;
	   clock_gettime(CLOCK_MONOTONIC, &res1);
	   sleep(3);
	   clock_gettime(CLOCK_MONOTONIC, &res2);
	   cout << res1.tv_sec << "," << res1.tv_nsec << endl;
	   cout << res2.tv_sec << "," << res2.tv_nsec << endl;
	 */
	return 0;
}
