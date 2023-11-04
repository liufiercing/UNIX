#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    int fd, cc, len;
    char buf[2048];
    char *p = NULL;

    int pid = fork();    
    if (pid < 0) {
        perror("fork error");
    } else if (pid == 0) {
        printf("pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(1);
        kill(getppid(), SIGKILL);
        
    } else {
        while (1);    
    }
    return 0;
}
