#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

typedef struct
{
	int n;
	char * * string;
} cmd;

int main(int argc, char * argv[])
{
	
	cmd * my_struct = malloc(sizeof(*my_struct));
	my_struct->string = malloc(sizeof(char *) * 10);
	for(int i = 0; i < 10; ++i)
	{
		my_struct->string[i] = malloc(sizeof(char) * 10);
	}
	for(int i = 0; i < 10; ++i)
	{
		strcpy(my_struct->string[i], "Hello");
		printf("%s\n", my_struct->string[i]);
	}
	/*
	char * * strings;
	strings = malloc(sizeof(char*) * 10);
	for(int i = 0; i < 10; ++i)
	{
		strings[i] = malloc(sizeof(char)*10);
	}
	for(int i = 0; i < 10; ++ i)
	{
		strcpy(strings[i], "Hello");
		printf("%s", strings[i]);
	}
	*/
	return 0;
}
