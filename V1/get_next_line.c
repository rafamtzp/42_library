/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:11:01 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/29 19:08:56 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static void	*freebufs(int freeleft_c, int freebuffer, char *left_c, char *buffer)
{
	if (freebuffer == 1 && buffer != 0)
		free(buffer);
	if (freeleft_c == 1 && left_c != 0)
		free(left_c);
	return (0);
}
static char	*append_to_left_c(char *left_c, char *buffer)
{
	char	*tmp;

	if (*left_c != '\0')
	{
		tmp = left_c;
		left_c = (char *)ft_strjoin(tmp, buffer);
		free(tmp);
	}
	else
	{
		free(left_c);
		left_c = ft_strdup(buffer);
	}
	return (left_c);
}

static char	*appendbufs(char *left_c, int fd, int *eoffoundptr)
{
	char	*buffer;
	int		foundending;
	int		bytesread;

	foundending = 0;
	while (foundending == 0 && *eoffoundptr == 0)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (buffer == 0)
			return (freebufs(1, 0, left_c, buffer));
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (freebufs(1, 1, left_c, buffer));
		else if (bytesread == 0)
			*eoffoundptr = 1;
		else if (ft_strchr(buffer, '\n') != 0)
			foundending = 1;
		left_c = append_to_left_c(left_c, buffer);
		free(buffer);
	}
	return (left_c);
}

static char	*setline(char *linebuf)
{
	char	*cursor;
	char	*left_c;

	cursor = linebuf;
	while (*cursor != '\n' && *cursor != '\0')
		cursor++;
	if (*cursor == '\n')
	{
		cursor++;
		left_c = ft_strdup(cursor);
	}
	else
		left_c = ft_strdup("");
	*cursor = '\0';
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*linebuf;
	static int	left_c_init = 0;
	static int	eoffound = 0;

	if (eoffound == 1)
		return (0);
	if (left_c_init == 0)
	{
		left_c = ft_strdup("");
		left_c_init = 1;
	}
	linebuf = appendbufs(left_c, fd, &eoffound);
	if (linebuf == 0)
		return (0);
	left_c = setline(linebuf);
	if (left_c == 0)
		return (0);
	if (*left_c == '\0')
	{
		left_c_init = 0;
		free(left_c);
	}
	return (linebuf);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *linebuf;
	int fd = open("file.txt", O_RDONLY);
	for (int i = 0; i < 10; i++)
	{
		linebuf = get_next_line(fd);
		printf("%s", linebuf);
		free(linebuf);
	}
	close(fd);
}*/