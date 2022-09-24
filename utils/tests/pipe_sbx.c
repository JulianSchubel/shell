#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
	char prg[] = {"ls"};
	char * args[] = {"ls", "-al", NULL};
	char piped_prg[] = {"wc"};
	char * piped_prg_args[] = {"wc", NULL};

	//Open two new file descriptors: [0] can be read from, [1] can be written to
	int pipe_fds[2];
	pipe(pipe_fds);
	printf("PIPE_INPUT: %d, PIPE_OUTPUT: %d\n", pipe_fds[0], pipe_fds[1]);
	pid_t pid1 = fork();
	//child 1
	//execvp(prg, args);
	
	if( pid1 == 0 )
	{
		dup2(pipe_fds[1], 1);
		execvp(prg, args);
	}
	pid_t pid2 = fork();
	if( pid2 == 0 ) 
	{
		dup2(pipe_fds[0], 0);
		close(pipe_fds[1]);
		close(pipe_fds[0]);
		execvp(piped_prg, piped_prg_args);
	}	
	//Only wait here once as, from testing, open file descriptors in subprocesses mean the process has not terminated
	waitpid(-1, NULL, 0);
	return 0;
}
