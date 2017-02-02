#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isInt(char *s);
void checkLen(char string[]);

int con = 65;

int main(int argc, char **argv)
{
	char str[con];
    char finalOut[2][5];
	char * pch;
    int count = 0;
    int quit = 0;
	printf("Assignment #1-6, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n");

    if(argc != 2)
    {
        printf("ERROR! Program 6 accepts 1 command line argument.\n");
        exit(0);
    }
    if(!isInt(argv[1]))
    {
        printf("ERROR! Expected integer argument.\n");
        exit(0);
    }

    int userIns = atoi(argv[1]);
    int argCount = 0;

    if(userIns == 0) exit(0);

    printf("> ");
	fgets(str, con-1, stdin);
    
    checkLen(str);

	pch = strtok(str, " \n\r");

    while(quit != 1)
    {
        if(argCount > userIns)
            exit(0);
	    while(count < 4)
        {
            if (count > 2) 
            {
                printf("ERROR! Incorrect number of tokens found.\n> ");
                fgets(str, con-1, stdin);
                checkLen(str);
                pch = strtok(str, " \n\r");
                count = 0;
            }
            else if(pch == NULL && count == 0)
            {
                printf("ERROR! Incorrect number of tokens found.\n> ");
                fgets(str, con-1, stdin);
                checkLen(str);
                pch = strtok(str, " \n\r");
                count = 0;
            }
            //else
            //{
                if(isInt(pch))
                {
                    strcpy(finalOut[count], "INT ");
                }
                else
                {
                    strcpy(finalOut[count], "STR ");
                }
                if((strcasecmp(pch, "quit") == 0))
                        quit = 1;
		        pch = strtok(NULL, " \n\r");
                count++;
                if(pch == NULL && (count == 2 || count == 1))
                {
                    if(count == 1 && quit == 1)
                        quit = 1;
                    else
                        quit = 0;

                    break;
                }
            //}

            argCount++;
	    }

        if(pch != NULL && strcasecmp(finalOut[0], "quit") == 0 && count == 1)
        {
                quit = 1; 
                break;
        }

        if(quit == 1) break;

        if((strcasecmp(finalOut[0], "INT ") == 0) && count == 2)
        {
            printf("ERROR! Expected STR INT.\n");
        }
        else if ((strcasecmp(finalOut[0], "INT ") == 0) && count == 1)
        {
            printf("ERROR! Expected STR.\n");
        }
        else if ((strcasecmp(finalOut[1], "STR ") == 0))
        {
            printf("ERROR! Expected STR INT.\n");
        }
        else
        {
            printf("%s%s\n", finalOut[0], finalOut[1]);
        }

        count = 0;
        
        memset(&finalOut[0], 0, sizeof(finalOut));
        memset(&finalOut[1], 0, sizeof(finalOut));

        printf("> ");
        fgets(str, con-1, stdin);
        checkLen(str);
	    pch = strtok(str, " \n\r");

        if(pch != NULL && strcasecmp(pch, "quit") == 0 && strlen(pch+1) == 0)
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
