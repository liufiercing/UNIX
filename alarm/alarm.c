 #include <unistd.h>
 #include <stdio.h>

 int main() {
    alarm(1);
    int i = 0;
    while (1) {
       printf("i = %d\n", i++);
    }
    return 0;
 }