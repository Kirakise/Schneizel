#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *s = NULL;
	int a = open("file.txt", O_RDONLY);
	while (get_next_line(a,&s))
	{
		printf("|%s\n", s);
		free(s);
	}
	printf("|%s\n", s);
	free(s);
	return (0);
}
