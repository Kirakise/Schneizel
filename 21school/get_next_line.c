#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_list lst;

	ft_getline(get_list(&lst, fd), line, fd);
	return (1);
}

int main()
{
	int a = open("file.txt", O_RDWR);
	char *s;

	get_next_line(a, &s);
	printf("%s", s);
}
