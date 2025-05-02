#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

char *ft_strjoin(char const *s1, char const *s2)
{
    char *s3;
    int i;
    int j;

    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (s3 == 0)
        return (0);
    i = 0;
    while (s1[i] != '\0')
    {
        s3[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        s3[i + j] = s2[j];
        j++;
    }
    s3[i + j] = '\0';
    return (s3);
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
    char *s1 = "hello,";
    char *s2 = " world!";

    char *s3 = ft_strjoin(s1, s2);
    printf("%s\n", s3);
}