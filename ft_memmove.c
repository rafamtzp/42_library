#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *ptr1;
    unsigned char *ptr2;

    ptr1 = (unsigned char *)src;
    ptr2 = (unsigned char *)dest;
    i = 0;
    while (i < n)
    {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
        i++;
    }
    return (dest);
}

void *ft_memmove(void *dest, const void*src, size_t n)
{
    unsigned char *tmp[n];
    ft_memcpy(tmp, src, n);
    ft_memcpy(dest, tmp, n);
    return (dest);
}

#include <stdio.h>
int main(void)
{
    char src[100] = "hello, world";
    /*
    int src[] = {1, 2, 3, 4, 5};
    int dest[100];
    */
    ft_memmove(src + 7, src, 13);
    printf("%s\n", src);
    /*
    for (int i = 0; i < 5; i++)
        printf("%i,\n", src[i]);*/
}