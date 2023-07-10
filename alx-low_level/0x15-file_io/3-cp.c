#include"file.h"
/**
 *main - Entry Point
 *@argv: array of strings
 *@argc: number of memebers
 *Return: 0 always success
*/
int main(int argc, char **argv)
{ 

        int fd1, fd2, r, w;
        char *buff;
        int fd_val1, fd_val2;
     if (argc != 3)
    {
         dprintf(STDERR_FILENO, "Usage: cp %s %s", argv[1],argv[2]);
         exit(97);
    }
      
        buff = malloc(sizeof(char) * 1024);
        if (buff == NULL)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
          exit (99);   
        }
    
        fd1 = open(argv[1], O_RDONLY);
        r = read (fd1, buff, 1024);
        fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
        do{
        if (fd1 == -1 || r == -1) 
        {
            dprintf(STDERR_FILENO, "Error: Can't read from %s", argv[1]);
          free(buff);
            exit(98);
        }
        w = write (fd2, buff, r);
        
        if (fd2 == -1 || w == -1)
        {
          dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
            free(buff);
          exit (99);  
        }
  r = read (fd1, buff, 1024);
        fd2 = open(argv[2], O_WRONLY | O_APPEND);
        }while(r > 0);

        free(buff);
        fd_val1 = close(fd1);            
        if (fd_val1 == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd1);
            exit (100);
        }
         fd_val2 = close(fd2);            
        if (fd_val2 == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd2);
            exit (100);
        }
      
    
   
        return(0);
}
