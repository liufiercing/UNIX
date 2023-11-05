#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    pid_t pid;
    int fd;
    pid = fork();
    if (pid > 0)
        exit(0);
    pid = setsid();
    if (pid == -1)
        perror("setsid error"); 

    int ch = chdir("/home/liuf");
    if (ch == -1)
        perror("chdir error");
    umask(0022); 

    close(STDIN_FILENO);
    fd = open("/dev/null", O_RDWR);
    if (fd == -1)
        perror("open error");
    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);

    while (1);

    return 0;
}