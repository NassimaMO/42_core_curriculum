int main(int argc, char **argv)
{
    int c;
    static int *a;
    static int *b;
    int len_a;
    int len_b;

    if (!number_checker())
        return (ft_printf("Error"), 0);
    c = 1;
    a = put_int_tab(argv, argc);
    b = malloc(sizeof(int) * argc);
    len_a = argc - 1;
    len_b = 0;
    while (c)
    {
        if (a && len_a > 1)
            sab(a);
        else if (b && len_b > 1)
            sab(b);
        else if (b && a && len_b > 1 && len_a > 1)
            ss(a, b);
        else if (b)
            pab(b, a);
        else if (a)
            pab(a, b);
        else if (a)
            rab(a);
        else if (b)
            rab(b);
        else if (a && b)
            rr(a, b);
        else if (a)
            rrab(a);
        else if (b)
            rrab(b);
        else if (a && b)
            rrr(a, b);
        if (nums_in_order(a, b))
            c = 0;
    }
    free(a);
    free(b);
}
