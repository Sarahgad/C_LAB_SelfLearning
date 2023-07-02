#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
/**
 *main - Entry Point
 *Practicing writing File Trough sys.call
 *Return: 0 always success
*/
int main(void)
{
    /*Declaration*/
    int fd;
    char buff[] = "No God Except Allah, & Mohamed The Massenger of Allah";
    /*Implement open file with creation mode, and permission*/

    fd = open("Shehadatin.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0)
    {
        perror("open");
    return (-1);
    }
    /*Implement Write file*/
    if (write(fd, buff, strlen(buff) > 1000))
    {
        perror("write");
        return (-1);
    }

    return (0);
}
