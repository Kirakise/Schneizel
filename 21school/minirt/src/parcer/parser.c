#include "../../includes/ultimate.h"
#include <fcntl.h>
#include <stdio.h>

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
		else if(parseline(s1) == -1)
		{
			free(s1);
			return (-1);
		}
	}
	parseline(s1);
	free(s1);
	return (1);
}

int parseline(char *s)
{
	if (s[0] == 'R')
		return(ParseRes(s + 1));
	else if (s[0] == 'A')
		return(ParseAmb(s + 1));
	else if (s[0] == 'c')
		return(ParseCam(s + 1));
	else if (s[0] == 'l')
		return(ParseLight(s + 1));
	else if (s[0] == 's' && s[1] == 'p')
		return(ParseSphere(s + 2));
	/*if (s[0] == 'p')
		return(ParsePlane(s));
	if (s[0] == 's' && s[1] == 'q')
		return(ParseSquare(s));
	if (s[0] == 'c')
		return(ParseCylinder(s));
	if (s[0] == 't')
		return(ParseTriangle(s));*/
	return (-1);
}
