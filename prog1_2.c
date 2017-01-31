#include <stdio.h>
#include <string.h>

int isInt(char *s);

int main()
{

	char str[65];
	char * pch;
	printf("Assignment #1-2, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n");
    printf("> ");
	fgets(str, 65, stdin);

	pch = strtok(str, " \n\r");
	while(pch != NULL)
	{
        if(isInt(pch))
        {
            printf("INT ");
        }
        else
        {
            printf("STR ");
        }
		pch = strtok(NULL, " \n\r");

	}

    printf("\n");

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
