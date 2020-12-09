#include "get_next_line.h"

int main()
{
	int a = open("file.txt", O_RDONLY);
	int b = open("file2.txt", O_RDONLY);
	char *s = NULL;
	get_next_line(a,&s);
	printf("%s\n", s);
	get_next_line(b,&s);
	printf("%s\n", s);
	get_next_line(a,&s);
	printf("%s\n", s);
	get_next_line(b,&s);
	printf("%s\n", s);
}
