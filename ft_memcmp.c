#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    unsigned char *ptr1;
    unsigned char *ptr2;

    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    i = 0;
    while (i < n)
    {
        if (*ptr1 != *ptr2)
            return (*ptr1 - *ptr2);
        i++;
        ptr1++;
        ptr2++;
    }
    return (0);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    char *s1 = "HElo cro";
    char *s2 = "Helo cro";

    printf("%i\n", ft_memcmp(s1, s2, 9));
}