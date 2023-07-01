#include<stdio.h>
/**
 *main - Entry point
 * Description: Practicing on file handling in functionsi
 * reading the string from the input and write it into the file
 *Return: 0 Always Success
*/

int main(void)
{
    /* Declare the file pointer */
    FILE *fp;
     char ch[100]; /*buffer array*/
    /*open the file by using fopen*/
    fp = fopen("sarah.text", "w+r");
    /*process the file*/
    fprintf(fp,"%s", fgets(ch, 50, stdin));
    /* close the file */    
    fclose(fp);
}