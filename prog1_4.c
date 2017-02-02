#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isInt(char *s);
void checkLen(char string[]);

int con = 22;

int main()
{
	char str[con];
    char finalOut[2][5];
	char * pch;
    int count = 0;
    int quit = 0;
	printf("Assignment #1-4, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n");
    printf("> ");
	fgets(str, con-1, stdin);
    
    checkLen(str);

	pch = strtok(str, " \n\r");

    if(pch != NULL && strcasecmp(pch, "quit") == 0)
            quit = 1; 

    while(quit != 1)
    {
	    while(count < 4)
        {
            if (count > 2) 
            {
                printf("ERROR! Incorrect number of tokens found.\n> ");
                fgets(str, con-1, stdin);
                checkLen(str);
                pch = strtok(str, " \n\r");
                count = 0;

                if(pch != NULL && strcasecmp(pch, "quit") == 0)
                {
                    quit = 1; 
                    break;
                }
            }
            else if(pch == NULL && count == 0)
            {
                printf("ERROR! Incorrect number of tokens found.\n> ");
                fgets(str, con-1, stdin);
                checkLen(str);
                pch = strtok(str, " \n\r");
                count = 0;

                if(pch != NULL && strcasecmp(pch, "quit") == 0)
                {
                    quit = 1; 
                    break;
                }
            }
            else
            {
                if(isInt(pch))
                {
                    strcpy(finalOut[count], "INT ");
                }
                else
                {
                    strcpy(finalOut[count], "STR ");
                }
		        pch = strtok(NULL, " \n\r");
                count++;
                if(pch == NULL && (count == 2 || count == 1))
                    break;
            }
	    }

        if(quit == 1) break;

        count = 0;

        printf("%s%s\n", finalOut[0], finalOut[1]);
        memset(&finalOut[0], 0, sizeof(finalOut));
        memset(&finalOut[1], 0, sizeof(finalOut));

        printf("> ");
        fgets(str, con-1, stdin);
        checkLen(str);
	    pch = strtok(str, " \n\r");

        if(pch != NULL && strcasecmp(pch, "quit") == 0)
            quit = 1;       
    }

}

int isInt(char *s)
{
    while(*s)
    {
        if((*s<'0' || *s>'9') && *s!='.') return 0;
        *s++;
    }

    return 1;
}

void checkLen(char *string)
{
    while(string[strlen(string)-1] != '\n') 
    {
        int dropped = 0;
        while(fgetc(stdin) != '\n')
            dropped++;

        if(dropped > 0)
        {
            printf("ERROR! Input string too long.\n> ");
            fgets(string, con, stdin);
        }
    }
}
