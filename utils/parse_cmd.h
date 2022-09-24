#ifndef PARSE_CMD_H
#define PARSE_CMD_H
#define DEFAULT_ARGS_CAPACITY 10
#define DEFAULT_DELIMITERS "\t\n\r "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_t.h"

cmd_t * parse_cmd(char * * string);

#endif
