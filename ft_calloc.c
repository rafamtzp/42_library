#include <stddef.h>
#include <stdlib.h>

void ft_bzero(void *s, size_t n)
{
        size_t i;
        unsigned char *ptr;

        ptr = (unsigned char *)s;
        i = 0;
        while (i < n)
        {
            *ptr = '\0';
            ptr++;
            i++;
        }
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    if (nmemb == 0 || size == 0)
        return (0);
    
    long long result = nmemb * size;
    if (nmemb != result / size)
        return (0);
    
    ptr = malloc(nmemb * size);
    if (ptr == 0)
        return (ptr);
    ft_bzero(ptr, nmemb * size);
    return (ptr);
}

#include <stdio.h>
int main(void)
{
    int *arr = ft_calloc(5, 4);
    for (int i = 0; i < 5; i++)
        printf("%i\n", arr[i]);
    free(arr);
}