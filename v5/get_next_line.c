#include "get_next_line.h"

// static char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	i;

// 	if (start + len > ft_strlen(s) && start < ft_strlen(s))
// 		len = ft_strlen(s + start);
// 	else if (start >= ft_strlen(s))
// 		len = 0;
// 	sub = ft_calloc(len + 1, 1);
// 	if (sub == 0)
// 		return (0);
// 	i = start;
// 	if (len == 0)
// 		return (sub);
// 	while (s[i] != '\0' && (i - start) < len)
// 	{
// 		sub[i - start] = s[i];
// 		i++;
// 	}
// 	return (sub);
// }

static char    *freebuf(char **ptr)
{
    if (*ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
    return (NULL);
}


static char *setline(char *linebuf)
{
    char    *leftovers;
    unsigned int l;

    while (*linebuf != '\n' && *linebuf)
        linebuf++;
    if (*linebuf == '\n')
        linebuf++;
    l = ft_strlen(linebuf);
    leftovers = ft_calloc(1, l + 1);
    if (!leftovers)
        return (NULL);
    l = 0;
    while (linebuf[l])
    {
        leftovers[l] = linebuf[l];
        l++;
    }
    *linebuf = '\0';
    return (leftovers);
}

static char *appendbufs(int fd, char *buffer, char *leftovers)
{
    char    *tmp;
    int bytesread;

    bytesread = BUFFER_SIZE;
    while (bytesread == BUFFER_SIZE && ft_strchr(buffer, '\n') == NULL)
    {
        bytesread = read(fd, buffer, BUFFER_SIZE);
        if (bytesread < 0)
            return (freebuf(&leftovers));
        else if (bytesread == 0)
            break ;
        if (!leftovers)
            leftovers = ft_strdup("");
        tmp = leftovers;
        leftovers = ft_strjoin(tmp, buffer); // get rid of frees here
        freebuf(&tmp);
        if (!leftovers)
            return (NULL);
    }
    return (leftovers);
}

char *get_next_line(int fd)
{
    char    *buffer;
    char    *linebuf;

    static char *leftovers;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (freebuf(&leftovers));
    buffer = ft_calloc(1, BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    linebuf = appendbufs(fd, buffer, leftovers); // old leftovers freed here
    freebuf(&buffer);
    if (!linebuf)
        return (NULL);
    leftovers = setline(linebuf);
    if (!leftovers)
        freebuf(&linebuf);
    else if (*leftovers == '\0')
        freebuf(&leftovers);
    return (linebuf);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *linebuf;
	int fd = open("42_no_nl", O_RDONLY);
    if (fd < 0)
        close(fd);
	for (int i = 1; i <= 9; i++)
	{
		linebuf = get_next_line(fd);
		printf("%s", linebuf);
		freebuf(&linebuf);
	}
	close(fd);
}
