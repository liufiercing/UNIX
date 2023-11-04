#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main( ) {
    int fd, cc;
    char buf[10] = "1zxc\n";
    char buf2[1024] = {};
    if ((fd = open("./1.txt", O_RDWR| O_CREAT | O_APPEND, 0644)) < 0) {
        perror("open error");
    }

    if ((cc = write(fd, buf, strlen(buf))) <= 0) {
        perror("write error");
    }
    lseek(fd, -cc, SEEK_CUR); 
    int fw = read(fd, buf2, 1024);
    write(STDOUT_FILENO, buf2, fw);

    if (close(fd) < 0) {
        perror("close error");
    }
    return 0;
}
