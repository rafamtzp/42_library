char *ft_strrchr(const char *s, int c)
{
    char *ptr;

    ptr = 0;
    while (*s)
    {
        if (*s == c)
            ptr = (char *)s;
        s++;
    }
    if (c == '\0')
    {
        ptr = (char *)s;
        return (ptr);
    }
    return (ptr);
}

#include <stdio.h>
int main(void)
{
    char *s = "helloh";
    char c = 'w';

    printf("s: %p, c in s: %p\n", s, ft_strrchr(s, c));
}