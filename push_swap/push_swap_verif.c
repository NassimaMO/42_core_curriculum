#include "push_swap.h"

int number_checker(char **argv, int argc)
{
    int i;
    int j;

    i = 1;
    if (argc <= 2)
        return (0);
    while (argc != 1)
    {
        j = 0;
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (0);
            j++;
        }
        i++;
        argc--;
    }
    return (1);
}