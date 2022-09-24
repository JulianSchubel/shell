#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	char * string = malloc(sizeof(char) * 10);
	strcpy(string, "ls -al");
	char * token;
	for(int i = 0; i < 10; ++i)
	{
		token = strsep(&string, " ");
		printf("%s", token);
	}
	return 0;
}
