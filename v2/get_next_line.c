/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:11:01 by ramarti2          #+#    #+#             */
/*   Updated: 2025/06/03 20:26:07 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start + len > ft_strlen(s) && start < ft_strlen(s))
		len = ft_strlen(s + start);
	else if (start >= ft_strlen(s))
		len = 0;
	sub = ft_calloc(len + 1, 1);
	if (sub == 0)
		return (0);
	i = start;
	if (len == 0)
		return (sub);
	while (s[i] != '\0' && (i - start) < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	return (sub);
}

static char	*freebufs(int freeleft, int freebuf, char *leftovers, char *buffer)
{
	if (freeleft == 1 && leftovers != 0)
		free(leftovers);
	if (freebuf == 1 && buffer != 0)
		free(buffer);
	return (0);
}

static char	*setline(char *linebuf) // not freeing leftovers here properly??
{
	char	*cursor;
	char	*leftovers;

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

static char	*appendbufs(char *leftovers, int fd, int *eofptr)
{
	char	*buffer;
	char *tmp;
	int		bytesread;
	int		nlfound;

	nlfound = 0;
	while (nlfound == 0 && *eofptr != 1)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (buffer == 0)
			return (freebufs(1, 0, leftovers, buffer));
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (freebufs(1, 1, leftovers, buffer));
		else if (bytesread == 0)
			*eofptr = 1;
		// else if (bytesread < BUFFER_SIZE) // maybe this could fix it? Try removing later?
		// {
		// 	tmp = buffer;
		// 	buffer = ft_substr(tmp, 0, bytesread + 1);
		// 	free(tmp);
		// 	if (buffer == 0)
		// 		return (freebufs(1, 0, leftovers, buffer));
		// }
		if (ft_strchr(buffer, '\n') != 0)
			nlfound = 1;
		tmp = leftovers;
		leftovers = ft_strjoin(leftovers, buffer);
		freebufs(1, 1, tmp, buffer);
		if (leftovers == 0)
			return (0);
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	char		*linebuf;
	static char	*leftovers;
	static int	eof = 0;
	static int	leftoversinit = 0;

	if (fd < -1 || eof == 1)
		return (0);
	if (leftoversinit == 0)
	{
		leftovers = ft_strdup("");
		if (leftovers == 0)
			return (0);
		leftoversinit = 1;
	}
	linebuf = appendbufs(leftovers, fd, &eof);
	if (linebuf == 0)
		return (0);
	leftovers = setline(linebuf);
	if (leftovers == 0)
		return (0);
	if (eof == 1 && *leftovers == '\0')
		free(leftovers);
	// if (eof == 1 && ft_strlen(linebuf) == 0)  // what is this for????????
	// 	return (0);
	return (linebuf);
}


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
