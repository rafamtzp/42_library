#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);

char *ft_strdup(const char *s)
{
    char *ptr;
    size_t len;

    len = ft_strlen(s);

    ptr = malloc(len + 1);
    if (ptr == 0)
        return (0);
    
    ft_memcpy(ptr, s, len + 1);

    return (ptr);
}

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

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

#include <stdio.h>
int main(void)
{
    char *s = "hello, world";
    char *dest = ft_strdup(s);
    printf("%s\n", dest);
    free(dest);
}