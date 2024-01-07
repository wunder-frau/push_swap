int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

long int    ft_atoi(const char *str)
{
    long int    nb;
    int            isneg;
    int            i;

    nb = 0;
    isneg = 1;
    i = 0;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (is_digit(str[i]))
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return (nb * isneg);
}