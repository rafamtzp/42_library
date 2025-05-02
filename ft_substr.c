#include <stddef.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;

    sub = malloc(len + 1);
    if (sub == 0)
        return (0);
    i = start;
    while (s[i] != '\0' && (i - start) < len)
    {
        sub[i - start] = s[i];
        i++;
    }
    sub[i - start] = '\0';
    return (sub);
}

#include <stdio.h>
int main(void)
{
    char const *s = "hello, world xxxxxx";
    unsigned int start = 7;
    size_t len = 5;
    printf("%s\n", ft_substr(s, start, len));
}