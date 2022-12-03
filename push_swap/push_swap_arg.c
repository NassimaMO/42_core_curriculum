int	number_checker(char **argv, int argc)
{
	int				i;
	int				j;
    int             x;
	long long int	nbr;
    char            **tab_tmp;

	i = 0;
    x = 0;
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][j])
			return (0);
        tab_tmp = ft_split(argv, ' ');
		while (tab_tmp[x] && tab_tmp[x][j])
		{
			if (!(tab_tmp[x][j] >= '0' && tab_tmp[x][j] <= '9') && \
				!(tab_tmp[x][j] == '-' && j == 0 && tab_tmp[x][j + 1]) && \
				!(tab_tmp[x][j] == '+' && j == 0 && tab_tmp[x][j + 1]))
				return (free_tab(tab_tmp), 0);
            j++;
            if (!tab_tmp[x][j])
            {
		        nbr = ft_atoi(tab_tmp[x]);
		        if (nbr > INT_MAX || nbr < INT_MIN || \
			        verif_double(tab_tmp[x], argv, argc, i))
			        return (free_tab(tab_tmp), 0);
                x++;
                j = 0;
            }
		}
        free_tab(tab_tmp);
	}
	if (argc <= 2)
		return (0);
	return (1);
}


// to verify for each tab of arg
int	verif_double(char *a, char **argv, int argc, int x)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i != x && ft_atoi(argv[i]) == ft_atoi(a))
			return (1);
		i++;
	}
	return (0);
}

int	*put_int_tab(char **argv, int argc)
{
	int	*a;
	int	i;
	int	j;

	i = 1;
	j = 0;
	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
		exit(1);
	while (i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (a);
}