#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd;
    char *filename = "test.txt";
    char *str = "Hello World\n";
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}
