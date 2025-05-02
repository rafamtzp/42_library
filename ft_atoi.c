
int ft_atoi(const char *nptr)
{
    int isminus;
    int num;

    while (*nptr == ' ' || *nptr == '\r' || *nptr == '\t' || *nptr == '\f'
         || *nptr == '\v' || *nptr == '\n')
         nptr++;
    isminus = 0;
    if (*nptr == '-')
    {
        isminus = 1;
        nptr++;
    }
    else if (*nptr == '+')
        nptr++;
    num = 0;
    while (*nptr >= '0' && *nptr <= '9')
    {
        num += (*nptr - '0');
        nptr++;
        if (*nptr >= '0' && *nptr <= '9')
            num = num * 10;
    }
    if (isminus == 1)
        return (-num);
    return (num);
}

/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    printf("%i\n", ft_atoi("           \n\t\f -+00000000000000012300000000abc567"));
}*/
