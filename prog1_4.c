#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInt(char *s);
void checkLen(char string[]);

int main()
{

	char str[20];
    char finalOut[2][5];
	char * pch;
    int count = 0;
	printf("Assignment #1-2, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n");
    printf("> ");
	fgets(str, 20, stdin);

    checkLen(str);

	pch = strtok(str, " \n\r");

	while(pch != NULL)
    {
        count++;
        if (count > 2) 
        {
            printf("ERROR! Incorrect number of tokens found.\n> ");
            fgets(str, 20, stdin);
            pch = strtok(str, " \n\r");
            count = 0;
        }
        else
        {
            if(isInt(pch))
            {
                strcpy(finalOut[count-1], "INT ");
            }
            else
            {
                strcpy(finalOut[count-1], "STR ");
            }
		    pch = strtok(NULL, " \n\r");
        }
	}

    printf("%s%s\n", finalOut[0], finalOut[1]);

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
    while(strlen(string) > 21) 
    {
        printf("ERROR! Input string too long.");
        fgets(string, 20, stdin);
    }
}
