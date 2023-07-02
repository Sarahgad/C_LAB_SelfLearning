#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
/**
 *main - Entry Point
 *Practicing Reading File Trough sys.call
 *Return: 0 always success
*/
int main(void)
{
    /*Declaration*/
    int fp; 
    /*unlike file handling with function,
    declaring the file output with integer of file decriptor,
    not FILE data struct*/
    char buff [100];
 /*Implement open file with system call*/
    fp = open("sarah.text", O_RDONLY);
    if(fp < 0)
    {
        perror("open");
        return -1;
    }
    /*implement reading file with system call*/
    if(read(fp, buff, 100) > 100)
    {
        perror("read");
        return -1;
    }
    /*Terminated the string by null*/
    buff[strlen(buff)] = '\0';
    printf ("file content: %s",buff);
    close(fp);
    return(0);
}