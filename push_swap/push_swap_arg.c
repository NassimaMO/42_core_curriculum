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
        tab_tmp = ft_split(argv[i], ' ');
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
			        verif_double(argv, argc, x, i))
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
int	verif_double(char **argv, int argc, int i, int x)
{
	int	n;
	int	**tab_tmp;
	int	num;
	int	w;

	n = 0;
	tab_tmp = ft_split(argv[i], ' ');
	num = ft_atoi(tab_tmp[x]);
	free_tab(tab_tmp);
	while (++n < argc)
	{
        tab_tmp = ft_split(argv[n], ' ');
		w = -1;
		while (tab_tmp[++w])
		{
			if (n != i && x != w && ft_atoi(tab_tmp[w]) == num)
				return (1);
		}
	}
	return (0);
}

int	*put_int_tab(char **argv, int argc)
{
	int	*a;
	int	i;
	int	j;
	int	w;
	int	**tab_tmp;

	i = 0;
	j = -1;
	a = malloc(sizeof(int) * get_num_param(argv, argc));
	if (!a)
		exit(1);
	while (++i < argc)
	{
		tab_tmp = ft_split(argv[i], ' ');
		w = -1;
		while (tab_tmp[++w])
			a[++j] = ft_atoi(tab_tmp[w]);
	}
	return (a);
}