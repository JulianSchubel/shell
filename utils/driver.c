#include "parse_cmd.h"
#include "display_cmd.h"
int main(int argc, char * argv[])
{
	char * string;
	string = malloc(sizeof(char) * 10);
	strcpy(string, "ls -al");
	cmd_t * cmd = parse_cmd(&string);
	display_cmd(cmd);
	return 0;
}
