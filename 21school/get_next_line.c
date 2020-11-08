#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_list lst;
	t_list *l = get_list(&lst, fd);

	*line = ft_getline(l, line, fd);
	return (1);
}

int main()
{
	int a = open("file.txt", O_RDWR);
	char *s;

	get_next_line(a, &s);
	printf("%s\n", s);
	get_next_line(a, &s);
	printf("%s\n", s);
}
