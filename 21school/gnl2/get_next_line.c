#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_list *lst;
	t_list *tmp;
	int	i;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
		lst = malloc(sizeof(struct s_list));
	lst->fd = -1;
	if(!(tmp = getlist(fd, lst)))
	{
		ft_clrlst(lst);
		return (-1);
	}
	i = ft_getline(fd, line, tmp);
	return (i);
}
