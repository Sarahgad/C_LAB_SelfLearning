#include"file.h"
/**
 *append_text_to_file -  a function that appends text at the end.
 *@filename: the name of file
 *@text_content: the content null terminated
 *Return: 1 always success
 */
int append_text_to_file(const char *filename, char *text_content)
{
/*declaration*/
int fd, writes;
/*Edge cases*/
if (filename == NULL)
    return(-1);
    fd = open(filename, O_WRONLY|O_APPEND);
    if (fd == -1)
    {
        perror("open");
        return (-1);
    }
    if (text_content != NULL)
    {
    writes = write(fd, text_content, strlen(text_content));
    if (writes == -1)
    {
        perror ("write");
        return (-1);
    }
    }
    close(fd);
    return(1);
}
