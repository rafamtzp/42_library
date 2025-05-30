/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:11:01 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/30 20:01:19 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (dest == 0 && src == 0 && n > 0)
		return (0);
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

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (ptr == 0)
		return (0);
	ft_memcpy(ptr, s, len + 1);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

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

static  void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*ptr = '\0';
		ptr++;
		i++;
	}
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	long long	result;

	if (nmemb != 0 && size != 0)
	{
		result = nmemb * size;
		if (nmemb != result / size)
			return (0);
	}
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	if (nmemb * size == 0)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if ((char)c == '\0')
		return (ptr);
	return (0);
}
char	*freebufs(int freeleft, int freebuf, char *leftovers, char *buffer)
{
	if (freeleft == 1)
		free(leftovers);
	if (freebuf == 1)
		free(buffer);
	return (0);
}

char *setline(char *linebuf)
{
	char *cursor;
	char *leftovers;

	cursor = linebuf;
	leftovers = 0;
	while (*cursor != '\n' && *cursor != '\0')
		cursor++;
	if (*cursor == '\n')
	{
		cursor++;
		leftovers = ft_strdup(cursor);
		*cursor = '\0';
	}
	else if (*cursor == '\0')
		leftovers = ft_strdup("");
	return (leftovers);
}
char *appendbufs(char *leftovers, int fd, int *eofptr)
{
	char *buffer;
	char *tmp;
	int bytesread;
	int nlfound;

	nlfound = 0;
	while (nlfound == 0 && *eofptr != 1)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (buffer == 0)
			return (freebufs(1, 1, leftovers, buffer));
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (freebufs(1, 1, leftovers, buffer));
		else if (bytesread == 0)
			*eofptr = 1;
		if (ft_strchr(buffer, '\n') != 0)
			nlfound = 1;
		tmp = leftovers;
		leftovers = ft_strjoin(leftovers, buffer);
		free(tmp);
		if (leftovers == 0)
			return (freebufs(1, 1, leftovers, buffer));
	}
	return (leftovers);
}

char *get_next_line(int fd)
{
	char *linebuf;

	static char *leftovers;
	static int eof = 0;
	static int leftoversinit = 0;
	if (fd < -1 || eof == 1)
		return (0);
	if (leftoversinit == 0)
	{
		leftovers = ft_strdup("");
		leftoversinit = 1;
	}
	linebuf = appendbufs(leftovers, fd, &eof);
	if (linebuf == 0)
		return (0);
	leftovers = setline(linebuf);
	if (leftovers == 0)
		return (0);
	if (eof == 1)
		free(leftovers);
	if (eof == 1 && ft_strlen(linebuf) == 0)
		return (0);
	return (linebuf);
}
// me dará problemas si uso un archivo vacío o sin salto de linea?????


#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *linebuf;
	int fd = open("file.txt", O_RDONLY);
	for (int i = 1; i <= 50; i++)
	{
		linebuf = get_next_line(fd);
		printf("%s", linebuf);
		free(linebuf);
	}
	close(fd);
}