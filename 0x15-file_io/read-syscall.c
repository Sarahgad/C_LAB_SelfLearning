#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
/**
 *main - Entry Point
 *Practicing Reading File Trough sys.call
 *Return: 0 always success
*/
int main(void)
{
    /*Declaration*/
    int fp;
    char buff [100];
    fp = open("sarah.text", O_RDONLY);
    if(fp < 0)
    {
        perror("open");
        return -1;
    }
    if(read(fp, buff, 100) > 100)
    {
        perror("read");
        return -1;
    }
    printf ("file content: %s",buff);
    close(fp);
    return(0);
}