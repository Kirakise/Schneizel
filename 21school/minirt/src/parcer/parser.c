#include "../../includes/get_next_line.h"
#include <fcntl.h>

int parsefile(char *s)
{
	int fd;
	char *s1;
	
	if ((fd = open(s, O_RDONLY)) < 3)
		return (-1);
	while (get_next_line(fd, &s1) > 0)
	{
		if (s1[0] == '\0')
		{
			free(s1);
			continue;
		}
		else if(parsefile(s1) == -1)
			return (-1);
	}
	return (1);
}

int parseline(char *s)
{
	if (s[0] == 'R')
		return(ParseRes());
	if (s[0] == 'A')
		return(ParseAmb());
	if (s[0] == 'c')
		return(ParseCam());
	if (s[0] == 'l')
		return(ParseLight());
	if (s[0] == 's' && s[1] == 'p')
		return(ParseSphere());
	if (s[0] == 'p')
		return(ParsePlane());
	if (s[0] == 's' && s[1] == 'q')
		return(ParseSquare());
	if (s[0] == 'c')
		return(ParseCylinder());
	if (s[0] == 't')
		return(ParseTriangle());
}
