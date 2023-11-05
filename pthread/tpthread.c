#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int val = 100;

void *tfun(void* arg){
    val = 10;
    // printf("thread pid = %d; tid = %lu\n", getpid(), pthread_self());
    printf("I'm thread: %d\n", val);
    return NULL;
}


int main () {
    pthread_t tid;
    printf("I'm main1: %d\n", val);
    tid = pthread_create(&tid, NULL, tfun, NULL);
    if (tid != 0) {
        perror("pthread create error");
    }

    sleep(1);
    printf("I'm main2: %d\n", val);
    return 0;
}