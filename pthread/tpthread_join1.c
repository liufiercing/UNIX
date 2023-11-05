#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int val = 100;

struct thrd
{
    int val;
    char str[256];
};

void *tfun(void* arg){

    return (void *)74;
}

int main () {
    pthread_t tid;
    int *reval;

    pthread_create(&tid, NULL, tfun, NULL);
  
    pthread_join(tid, (void**)&reval);
    
    printf("val = %d\n", (void *)reval);
    pthread_exit(NULL);
    // sleep(1);
    // printf("I'm main2: %d\n", val);
    // return 0;
}