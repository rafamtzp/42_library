#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int len;
	unsigned int i;
	char	*ms;


	len = ft_strlen(s);
	ms = malloc(len + 1);
	if (ms == 0)
		return (0);
	ms[len] = '\0';
	i = 0;
	while (s[i])
	{
		ms[i] = f(i, s[i]);
		i++;
	}
	return (ms); 
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

char func(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z' && i % 2 == 1)
		return ('x');
	return (c);
}



#include <stdio.h>
int main(void)
{
	char *s = "hello, world";
	printf("%s\n", ft_strmapi(s, func));
}