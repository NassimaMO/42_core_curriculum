#include "get_next_line.h"

char	*ft_line(char *l)
{
	int	i;
	char *new;

	i = 0;
	while (l[i] && l[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (l[i] && l[i] != '\n')
	{
		new[i] = l[i];
		i++;
	}
	if (l[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	free(l);
	return (new);
}

void	ft_rm_bn(char **buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		while (buf[i])
		{
			i++;
			buf[j] = buf[i];
			j++;
		}
	}
}

char    *get_next_line(int fd)
{
	static char	*buf[FOPEN_MAX];
	char	*nl;
	int		c;
	
	buf[fd] = ft_calloc(1, BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
		return (NULL);
	nl = ft_strdup("");
	nl = ft_strjoin(nl, buf[fd]);
	c = 1;
	while (ft_strchr(nl, '\n') == 0 && c)
	{
		c = read(fd, buf[fd], BUFFER_SIZE);
		buf[c] = '\0';
		nl = ft_strjoin(nl, buf[fd]);
	}
	if (!c && nl[0] == 0)
	{
		free(nl);
		return (NULL);
	}
	nl = ft_line(nl);
	ft_rm_bn(buf[fd]);
	return (nl);
}
/*#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;

	fd = open("gnlTester/files/big_line_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
	close(fd);
}*/
