#include <stddef.h>

int	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    char *ptr;
    unsigned int i;
    int j;

    ptr = 0;
    i = 0;
    while (big[i] && i < len)
    {
        j = 0;
        if (big[i] == little[j])
            ptr = (char *)&big[i];
        while (big[i + j] == little[j] && little[j])
            j++;
        if (j == ft_strlen(little))
            return (ptr);
        i++;
    }
    return (ptr);
}

#include <stdio.h>
int main(void)
{
    const char *big = "hellowwaldoaaafxyz";
    const char *little = "waldo";
    printf("Address of big: %p \nAddress of little in big: %p\n", big, ft_strnstr(big, little, 50));
    printf("%s\n", ft_strnstr(big, little, 50));
}
