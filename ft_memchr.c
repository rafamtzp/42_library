#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;
    unsigned char *cursor;

    ptr = 0;
    cursor = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        if (*cursor == c)
        {
            ptr = cursor;
            return (ptr);
        }
        cursor++;
        i++;
    }
    return (ptr);
}

#include <stdio.h>
int main (void)
{
    char *s = "hello, cro how are u";
    char *find = ft_memchr(s, 'c', 21);
    printf("%s\n%s\n", s, find);

}
