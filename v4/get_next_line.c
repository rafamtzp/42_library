/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:11:01 by ramarti2          #+#    #+#             */
/*   Updated: 2025/06/05 18:52:43 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *freebuf(char *buf)
{
	if (buf != 0)
	{
		free(buf);
		buf = NULL;
	}
	return (NULL);
}

static char	*setline(char *linebuf) // not freeing leftovers here properly??
{
	char *cursor;
	char *leftovers;

	cursor = linebuf;
	leftovers = NULL;
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

static char	*appendbufs(char *leftovers, int fd, int *eofptr, int *countptr)
{
	int nlfound;
	int bytesread;
	char *buffer;

	nlfound = 0;
	while (*eofptr != 1 && nlfound != 1)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0) // cambiar a menor o igual me da menos KOS pero mas segfaults y valgrinds
			return (buffer = freebuf(buffer));
		else if (bytesread == 0 && *leftovers == '\0') // si leftovers está vacío, y 0 bytes leidos, fin archivo y no hay mas q hacer
		{
			*eofptr = 1;
			return (buffer = freebuf(buffer));
		}
		else if ((bytesread > 0 && bytesread < BUFFER_SIZE) || (bytesread == 0 && *countptr > 0)) // segunda opcion asume q todavia hay leftovers y queremos seguir
			*eofptr = 1;
		*countptr += 1;
		if (ft_strchr(buffer, '\n') != 0)
			nlfound = 1;
		leftovers = ft_strjoin(leftovers, buffer); // libero leftovers antiguo aqui.
		if (leftovers == NULL)
			return (buffer = freebuf(buffer));
		free(buffer);
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	char	*linebuf;

	static char *leftovers = NULL;
	static int eof = 0;
	static int readcount = 0;
	if (fd < 0 || (leftovers == NULL && eof == 1))
	{
		if (leftovers != 0)
			return (leftovers = freebuf(leftovers));
		return (0);
	}
	if (leftovers != NULL && eof == 1) // recortado por invalid read
		return (leftovers);
	if (leftovers == NULL)
		leftovers = ft_strdup("");
	linebuf = appendbufs(leftovers, fd, &eof, &readcount);
	if (linebuf == NULL)
		return (leftovers = freebuf(leftovers));
	leftovers = setline(linebuf);
	if (leftovers == NULL)
		return (linebuf = freebuf(linebuf));
	if (*leftovers == '\0' && eof == 1) // añadido
		leftovers = freebuf(leftovers);
	return (linebuf);
}


// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char *linebuf;
// 	int fd = open("file.txt", O_RDONLY);
// 	for (int i = 1; i <= 2; i++)
// 	{
// 		linebuf = get_next_line(fd);
// 		printf("%s", linebuf);
// 		free(linebuf);
// 	}
// 	close(fd);
// }
