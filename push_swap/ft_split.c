#include "stdio.h"
#include "stdlib.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strc(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int len_tab(char *str, char c, int len)
{
	int i;
	int len_tab;

	i = -1;
	while (str[++i] && i < len)
	{
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] == c)
			i++;
		len_tab++;
	}
	return (len_tab);
}

char    **ft_split(char *str, char c)
{
	char **tab;
	int len_str;
	int i;
	int chr;
	int word;

	i = 0;
	word = 0;
	len_str = ft_strlen(str);
	tab = malloc(sizeof(char *) * len_tab(str, c, len_str));
	while (str[i] && i < len_str)
	{
		while (str[i] == c)
			i++;
		chr = 0;
		tab[word] = malloc(sizeof(char) * ft_strc(str + i, c) + 1);
		while (str[i] && str[i] != c)
			tab[word][chr++] = str[i++];
		tab[word][chr] = '\0';
		while (str[i] == c)
			i++;
		word++;
	}
	return (tab);
}

/*int main(int argc, char **argv)
{
	char    **tab;
	int     i;

	tab = ft_split(argv[1], ' ');
	i = -1;
	while (tab[++i])
		printf("%s;\n", tab[i]);
	return (0);
}*/