#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_list lst;
	int a;
	lst.i = 0;
	if (line == 0)
		return (-1);
	t_list *l = get_list(&lst, fd);
	a = ft_getline(l, &line, fd);
	return (a);
}

int main()
{
	int a = open("file.txt", O_RDWR);
	int b = open("file2.txt", O_RDWR);
	char *s;
	int j;

	j = get_next_line(a, &s);
	printf("%s %i\n", s, j);
	j = get_next_line(0, &s);
	printf("%s %i\n", s, j);
	j = get_next_line(b, &s);
	printf("%s %i\n", s, j);
	j = get_next_line(a, &s);
	printf("%s %i\n", s, j);

}
