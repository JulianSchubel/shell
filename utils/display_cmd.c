#include "display_cmd.h"

void display_cmd(cmd_t *cmd)
{
	printf("ORIGINAL COMMAND: %s\n", cmd->cmd);
	printf("PROGRAM NAME: %s\n", cmd->prg_name);	
	printf("ARGUMENT COUNT: %d\n", cmd->argc);	
	printf("ARGUMENT ARRAY CAPACITY: %d\n", cmd->capacity);	
	printf("ARGUMENTS:\n");
	for(unsigned int i = 0; i < cmd->argc; ++i)
	{
		printf("\tARGUMENT %d: %s\n", i, cmd->args[i]); 
	}
}
