double	ft_double_atoi(char *str)
{
	double	res0 = 0;
	double	res1 = 0;
	int		i = 0;
	
	while (str[i] >= 48 && str[i] <= 57)
	{
		res0 = res0 * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '/')
	{
		i++;	
		while (str[i] >= 48 && str[i] <= 57)
		{
			res1 = res1 * 10 + (str[i] - '0');
			i++;
		}
}
	return (res0 / res1);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && ((unsigned char)s1[i] || (unsigned char)s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
