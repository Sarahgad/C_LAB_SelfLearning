#include "file.h"
/**
 *create_file - a function that creates a file. 
 *@filename: name of file that created
 *@text_content: the texet you write
 *Return: 1 always success. 
*/
int create_file(const char *filename, char *text_content)
{
/*Declaration*/
int fd;
int writes;
/*creating file*/
    fd = open(filename ,  O_CREAT | O_RDONLY | O_TRUNC, 0600);
    writes = write(fd, text_content, strlen(text_content));
    if (fd == -1 || writes == -1)
    {
        return (-1);
    }
    close(fd);
    return (1);

    }






