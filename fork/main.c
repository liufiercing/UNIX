#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int main(){
    int i, ret;
    int fd[2];
    ret = pipe(fd);

    for (i = 0; i < 2; i++) {
        pid_t f = fork();
        if (f == 0)
            break;
    }
    if (i == 2){
        close(fd[0]);
        close(fd[1]);
        printf("pid = %d\n", getpid());
        wait(NULL);
        wait(NULL);

    } else if (i == 0) {        // 兄
        close(fd[0]); // 读
        dup2(fd[1], STDOUT_FILENO);  // 写
        execlp("ls", "ls", "-l", NULL);
        perror("兄");
        // printf("child pid = %d\n", getpid());
        // printf("parent gpid = %d\n", getppid());
        
    } else if (i == 1) {        //第
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
        perror("兄");
        // printf("child pid = %d\n", getpid());
        // printf("parent gpid = %d\n", getppid());
        
    }

    return 0;
}