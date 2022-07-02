/*ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.*/
/*rb (rotate b): Shift up all elements of stack b by 1.The first element becomes the last one.*/
#include "../push_swap.h"

void rab(int *ab)
{
    int tmp;
    int i;

    i = 0;
    tmp = ab[0];
    while (ab && ab[i])
    {
        ab[i] = ab[i + 1];
        i++;
    }
    ab[i - 1] = tmp;
}

/*int main(void)
{
    static int *ab;

    ab = malloc(sizeof(int) * 5);
    ab[0] = 5;
    ab[1] = 8;
    ab[2] = 9;
    ab[3] = 4;
    ab[4] = '\0';
    rab(ab);
    printf("%d\n", ab[0]);
    printf("%d\n", ab[1]);
    printf("%d\n", ab[2]);
    printf("%d\n", ab[3]);
    printf("%d\n", ab[4]);
    free(ab);
}*/