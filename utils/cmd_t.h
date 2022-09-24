#if !defined (CMD_T_H)
#define CMD_T_H
typedef struct
{
	char * cmd;
	char * prg_name;
	unsigned int capacity;
	unsigned int argc;
	char * * args;
	
} cmd_t;
#endif
