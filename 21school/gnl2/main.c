#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int a = open("file.txt", O_RDONLY);
	int b = open("fewchar_perline.txt", O_RDONLY);
	char *s = NULL;
	int i = 0;
	while(get_next_line(b, &s))
	{
		i++;
		printf("%s|\n",s);
	//	get_next_line(b, &s);
	//	printf("%s\n", s);
	}
	printf("%s|\n", s);
	printf("%i\n", ++i);
	free(s);
}
