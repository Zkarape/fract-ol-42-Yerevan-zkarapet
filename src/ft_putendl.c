#include <unistd.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void	ft_putendl(char *s)
{
	char	n;

	n = '\n';
	write(1, s, ft_strlen(s));
	write(1, &n, 1);
}
