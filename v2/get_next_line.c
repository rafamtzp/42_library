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

#include "get_next_line.h"

static char	*freebufs(int freeleft, int freebuf, char *leftovers, char *buffer)
{
	if (freeleft == 1)
		free(leftovers);
	if (freebuf == 1)
		free(buffer);
	return (0);
}

static char	*setline(char *linebuf)
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
	char	*tmp;
	int		bytesread;
	int		nlfound;

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
		if (leftovers == 0)
			return (freebufs(1, 0, leftovers, buffer));
		freebufs(1, 1, tmp, buffer);
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

/*
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
}*/