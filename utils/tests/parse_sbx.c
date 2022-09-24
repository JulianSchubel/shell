#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int counter = 0;
	char *input_string, *val, *prgname;
	char * args[10];
	int i = 0;
	size_t input_size;
	getline(&input_string, &input_size, stdin);
	while( (val = strtok(input_string, " ")) != NULL )		
	{
		if(counter != 0)
		{
			args[i++] = val;
		}
		else
		{
			prgname = val;
			++counter;
		}
		input_string = NULL;		
	}
	printf("%s\n", prgname);
	args[i] = NULL;
	for(int j = 0; j < 10 && args[j] != NULL; ++j)
	{
		printf("%s", args[j]);
	}
	pid_t pid = fork();
	if(pid == 0)
	{
		execvp(prgname, args);
	}
	wait(NULL);
}
