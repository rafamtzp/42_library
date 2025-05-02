// strlcat appends nul-terminated src to the END of dst.
// appends at MOST (size - srlen(dest)) - 1 bytes from src to dst
// hence size = non-null_srcchars + strlen(dest) + nullbyte
#include <stddef.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    int dstlen;
    int srccount;
    int limit;

    dstlen = 0;
    while (*dst)
    {
        dstlen++;
        dst++;
    }
    srccount = 0;
    limit = size - dstlen - 1;
    while (*src && srccount < limit)
    {
        *dst = *src;
        dst++;
        src++;
        srccount++;
    }
    while (*src)
        srccount++;
    *dst = '\0';
    return (srccount + dstlen);
}

#include <stdio.h>
int main(void)
{
    char dst[100] = "hello, ";
    char *src = "world";
    printf("resulting string has %zu chars\n", ft_strlcat(dst, src, 5 + 7 + 1));
    printf("%s\n", dst);
}