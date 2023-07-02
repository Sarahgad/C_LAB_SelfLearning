#include"file.h"
/**
*read_textfile - reads a text file and prints it.
*@filename: pointer to point file name
*@letters: unsigned integers indicate to no. of letters in the file
*Return: (writes) always success.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
    /*Declaration*/
   ssize_t fd; /*declare the file decriptor with ssize_t because if comparisomn*/
    char *buff;
    ssize_t reads, writes;

    /*allocate the buff on the heap*/
    buff = malloc(sizeof(char) * letters);
    if (buff == NULL)
    {
        return (0);
    }
    /*open file - set the variable withpit double qoutes*/
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (0);
    }
    /*read file*/
    reads = read(fd, buff, letters);
    if (reads >(ssize_t) letters)
    {
        perror("reads");
        return (0);
    }
    /*print file*/
    writes = write(STDOUT_FILENO, buff, reads);
    if (writes > reads) 
    {
        return (0);
    }
 close(fd);
free(buff); 
return(writes);

}

