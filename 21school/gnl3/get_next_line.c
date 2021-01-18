#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_str	arr[4096];

	if (fd <= 0 || !line || read(fd, NULL, 0))
		return (-1);
	*line = malloc(1);
	**line = 0;
	return(ft_getline(fd, &(arr[fd]), line));
}
