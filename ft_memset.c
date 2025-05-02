#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        *ptr = c;
        ptr++;
        i++;
    }
    return (s);
}

#include <stdio.h>
int main(void)
{
    unsigned int i = 0;
    size_t n = 4;
    char s[100];
    ft_memset(s, 'x', n);
    while (i < n)
    {
        printf("%c\n", s[i]);
        i++;
    }
}