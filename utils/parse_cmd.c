#include "parse_cmd.h"

cmd_t * parse_cmd(char **string)
{
	char * token;
	int i = 0;
	//Allocating memory for structure.
	cmd_t *cmd = malloc(sizeof(*cmd));
	//Allocating memory for the duplicate of the original input string.
	cmd->cmd = calloc(1, strlen(*string));
	//Store a copy of the original string.
	cmd->cmd = strdup(*string);
	//Initialize the capacity for the args array.
	cmd->capacity = DEFAULT_ARGS_CAPACITY;
	//Initialize the argument counter (argc) to 0.
	cmd->argc = 0;
	//Allocate memory for the arguments array 0 initialized.
	//Using calloc as execvp requires null pointer terminated array.
	cmd->args = calloc(DEFAULT_ARGS_CAPACITY, sizeof(char *));
	
	//Parsing the input string
	while( (token = strtok(*string, DEFAULT_DELIMITERS)) != NULL )
	{
		++cmd->argc;
		cmd->args[i++] = token;	
		//strtok requires string to be NULL after the first pass in order to travers the string for further tokens.
		*string = NULL;
	}
	//Assign the prg_name to be equal to the first token in the args array.
	cmd->prg_name = cmd->args[0];
	return cmd;
}
