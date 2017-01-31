#include <stdio.h>
#include <string.h>

int main()
{

	char str[65];
	char * pch;
	printf("Assingment #1-1, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n");
	fgets(str, 65, stdin);

	char *pos;
	if((pos=strchr(str, '\n')) != NULL) 
		*pos = '\0';

	pch = strtok(str, " ");
	while(pch != NULL)
	{

		printf("=%s=\n", pch);
		pch = strtok(NULL, " ");

	}

}
