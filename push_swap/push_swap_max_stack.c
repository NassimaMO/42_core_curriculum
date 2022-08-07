#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (n)
	{
		((char *)s)[i] = '\0';
		n--;
		i++;
	}
}

static int in_index(int x, int *i, int len_i)
{
    int index;

    index = 0;
    while (index != len_i)
    {
        if  (x == i[index])
            return (1);
        index++;
    }
    return (0);
}

static int is_it_really(t_stacks *stacks, int x, int *i, int len_i)
{
    int index;

    index = 0;
    if (in_index(x, i, len_i))
        return (0);
    while (index != stacks->len_a)
    {
        if (x < stacks->a[index] && !in_index(stacks->a[index], i, len_i))
            return (0);
        index++;
    }
    return (1);
}

static int is_next_max(t_stacks *stacks, int x, int *i, int len_i)
{
    int index;

    index = 0;
    if (in_index(x, i, len_i))
        return (0);
    while (index != stacks->len_a)
	{
		if (stacks->a[index] > x && is_it_really(stacks, stacks->a[index], i, len_i))
            return (0);
		index++;
	}
    return (1);
}

int *next_max_stack(t_stacks *stacks)
{
    int *i;
    int len_i;
    int index;

    index = 0;
    len_i = 0;
    i = malloc(sizeof(int) * stacks->len_a);
	ft_bzero(i, stacks->len_a);
    while (index < stacks->len_a)
    {
        if (is_next_max(stacks, stacks->a[index], i, len_i))
        {
            i[len_i] = stacks->a[index];
            len_i++;
            index = 0;
        }
        index++;
        if (index >= stacks->len_a && len_i < stacks->len_a)
            index = 0;
    }
    return (i);
}

/*int main()
{
    t_stacks stacks;
    int *a;
    int *i;
    int index;

    index = 0;
    a = malloc(sizeof(int) * 9);
    a[0] = 12;
    a[1] = 1;
    a[2] = 78;
    a[3] = 96;
    a[4] = 23;
    a[5] = -5;
    a[6] = 48;
    a[7] = 0;
    a[8] = 0;
    stacks.len_a = 8;
    stacks.a = a;
    i = malloc(sizeof(int) * stacks.len_a);
    ft_bzero(i, stacks.len_a);

    while  (index != stacks.len_a)
    {
        printf("next_max = %d\n", next_max_stack(i, &stacks));
        index++;
    }
    free(a);
    free(i);
}*/