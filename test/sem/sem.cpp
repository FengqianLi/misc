#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

using namespace std;

sem_t *binSem = new sem_t();

struct timespec ts;

void* helloWorld(void *arg) {
    while(1) {
        ts.tv_sec = time(NULL) + 1;
        sem_timedwait(binSem, &ts);
        //sem_wait(binSem);
        cout << "helloWorld" << endl;
    }
}

int main() {
    int res = 0;
    res = sem_init(binSem, 0, 0);
    if(res) {
        cout << "semaphore initialization failed!!" <<endl;
        return 0;
    }

    pthread_t thdHelloWorld;
    res = pthread_create(&thdHelloWorld, NULL, helloWorld, NULL);
    if(res) {
        cout << "Thread create failed!!" << endl;
        return 0;
    }

    //while(true) {
    cout << "In main, sleep several seconds" << endl;
    sleep(1);
    sem_post(binSem);
    //sleep(1);
    //}

    void *threadResult;
    res = pthread_join(thdHelloWorld, &threadResult);
    if(res){
        cout << "Thread join failed!" << endl;
        return 0;
    }
    sem_destroy(binSem);

    return 0;
}
