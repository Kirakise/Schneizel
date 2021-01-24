int ParseRes(char *s)
{
	int i;

	i = 1;
	while (s[i] == ' ')
		i++;
	g_data.Swidth = ft_atoi(s + i);
	while (s[i] != ' ')
		i++;
	g_data.Sheight = ft_atoi(s + i);
	if (g_data.Swidth < 1 || g_data.Sheight < 1)
		return (-1);
	return (1);
}

int ParseAmb(char *s)
{
	
}