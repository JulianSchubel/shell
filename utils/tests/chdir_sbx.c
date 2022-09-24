#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	int ret = chdir("../");
	printf("%d\n", ret);
	return 0;
}

