#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInt(char *s);

int main()
{

	char str[65];
    char finalOut[2][5];
	char * pch;
    int count = 0;
	printf("Assignment #1-3, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n");
    printf("> ");
	fgets(str, 65, stdin);

	pch = strtok(str, " \n\r");

	while(count < 4)
    {
        if (count > 2) 
        {
            printf("ERROR! Incorrect number of tokens found.\n> ");
            fgets(str, 65, stdin);
            pch = strtok(str, " \n\r");
            count = 0;
        }
        else if(pch == NULL && count == 0)
        {
            printf("ERROR! Incorrect number of tokens found.\n> ");
            fgets(str, 65, stdin);
            pch = strtok(str, " \n\r");
            count = 0;
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
            if(pch == NULL && count == 2)
                break;
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

