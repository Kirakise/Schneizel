#include "get_next_line.h"

int main()
{
	int a = open("file.txt", O_RDONLY);
	int b = open("file2.txt", O_RDONLY);
	char *s = NULL;
	while(get_next_line(0,&s))
	{
		printf("%s\n", s);
	}
	printf("%s", s);
}
