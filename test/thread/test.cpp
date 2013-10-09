#include <pthread.h>
#include <iostream>
#include <time.h>

using namespace std;

pthread_t thr, t2;

void * 
hello(void *arg){
    cout << "start" << endl;
    sleep(3);
    cout << "end" << endl;
    pthread_exit(NULL);
}

void * hello2(void *arg) {
    pthread_join(thr, NULL);
    cout << "this is thread 2" << endl;
}

int 
main(int argc, char **argv){
    //pthread_t thr, t2;
    pthread_create(&thr, NULL, &hello, NULL);
    pthread_create(&t2, NULL, &hello2, NULL);

    //struct timespec ts;
    //ts.tv_sec = time(NULL) + 1;
    //pthread_timedjoin_np(thr, NULL, &ts);
    pthread_join(thr, NULL);
    pthread_join(t2, NULL);

    if(pthread_equal(thr, pthread_self()) == 0) {
        cout << "equal threads" << endl;
    }
    else {
        cout << "inequal threads" << endl;
    }
    return 0;
}
