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

