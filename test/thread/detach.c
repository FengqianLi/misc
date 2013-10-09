#include <stdio.h>
#include <pthread.h>

void *testFunction()
{

    pthread_attr_t attr;
    int chk, rc;

    pthread_attr_init(&attr);
    printf("thread_attr_init: %d\n", rc);

    pthread_attr_getdetachstate(&attr, &chk);
    printf("thread_attr_getdetachedstate: %d\n", rc);

    if (chk == PTHREAD_CREATE_DETACHED)
        printf("Detached\n");
    else if (chk == PTHREAD_CREATE_JOINABLE)
        printf("Joinable\n");

    return NULL;
}

int main(int argc, const char *argv[])
{

    pthread_t thread1;
    pthread_attr_t attr;

    int rc;

    rc = pthread_attr_init(&attr);

    printf("attr_init: %d\n", rc);
    rc = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    printf("attr_setdetachedstate: %d\n", rc);

    rc = pthread_create(&thread1, &attr, testFunction, NULL);
    printf("attr_create: %d\n", rc);

    sleep(4);
    pthread_cancel(thread1);

    return 0;
}
