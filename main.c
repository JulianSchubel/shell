/* **************************************
	Title:		Shell
	Author:		Julian Schubel
	Contact:	schublejulian@gmail.com

	History:
************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "./utils/parse_cmd.h"

int main(int argc, char * argv[])
{
	//REPL sentinal value
	int repl_state = 1;

	//REPL 
	while(repl_state)
	{
		size_t size = 10;	
		char * cd = "cd";
		char * input = malloc(sizeof(char) * size);
		fputs("simple_shell> ", stdout);
		getline(&input, &size, stdin);
		cmd_t * cmd = parse_cmd(&input);
		//Accommodating for programs (builtins) that need to act on the parent process itself
		if( !strcmp(cmd->prg_name, cd) )
		{
			int sigint = chdir(cmd->args[1]);
			(sigint != 0) ? printf("Directory not found.\n") : 0;	
		}
		else
		{
			pid_t pid = fork();
			//Execute in the child process; Fork returns 0 in the child process.
			if(pid == 0)
			{
				execvp(cmd->prg_name, cmd->args);
			}
			//-1: wait for child processes, NULL: do not return a wait status, 0: No options
			waitpid(-1, NULL, 0);
		}
	}
	return 0;
}
