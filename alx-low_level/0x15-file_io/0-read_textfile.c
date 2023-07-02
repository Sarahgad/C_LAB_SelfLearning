#include"file.h"
/**
*read_textfile - reads a text file and prints it.
*@filename: pointer to point file name
*@letters: unsigned integers indicate to no. of letters in the file
*Return: (reads) always success.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
    /*Declaration*/
    int fd;
    char *buff;
    ssize_t reads, writes;

    /*allocate the buff on the heap*/
    buff = malloc(sizeof(char) * letters);
    if (buff == NULL)
    {
        return (NULL);
    }
    /*open file*/
    fd = open("filename", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (0);
    }
    /*read file*/
    reads = read(fd, buff, letters);
    if (reads > letters)
    {
        perror("reads");
        return (0);
    }
    /*print file*/
    writes = write(1, buff, reads);
    if (write > reads) 
    {
        return (0);
    }   
return (reads);

}