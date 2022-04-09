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
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    char buf[1024];
    int n;
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(STDOUT_FILENO, buf, n);
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    int i;
    for (i = 0; i < 5; i++)
    {
        n = read(fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    lseek(fd, -5, SEEK_END);
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(STDOUT_FILENO, buf, n);
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    int fd2;
    fd2 = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1)
    {
        perror("open");
        exit(1);
    }
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(fd2, buf, n);
    }
    close(fd);
    close(fd2);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    fd2 = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1)
    {
        perror("open");
        exit(1);
    }
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(fd2, buf, n);
    }
    close(fd);
    close(fd2);
    unlink(filename);
    unlink("test2.txt");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    fd2 = open("test2.txt", O_RDONLY);
    if (fd2 == -1)
    {
        perror("open");
        exit(1);
    }
    char buf2[1024];
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(STDOUT_FILENO, buf, n);
    }
    while ((n = read(fd2, buf2, sizeof(buf2))) > 0)
    {
        write(STDOUT_FILENO, buf2, n);
    }
    close(fd);
    close(fd2);
    unlink("test.txt");
    unlink("test2.txt");
    return 0;
}
