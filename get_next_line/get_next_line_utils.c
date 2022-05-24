#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = 0;
	while (s[i])
		i++;
	d = malloc((i + 1) * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = ((char *)s)[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void	ft_fill(char const *s1, char const *s2, char *temp)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1 && s2))
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = 0;
		return (temp);
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	j += i;
	temp = malloc(sizeof(char) * j + 1);
	if (!temp)
		return (NULL);
	ft_fill(s1, s2, temp);
	free(s1);
	return (temp);
}