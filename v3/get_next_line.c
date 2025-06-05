/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:11:01 by ramarti2          #+#    #+#             */
/*   Updated: 2025/06/05 14:21:33 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
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

// static char	*freebufs(char *buffer1, char *buffer2)
// {
// 	if (buffer1)
// 	{
// 		free(buffer1);
// 		buffer1 = NULL;
// 	}
// 	if (buffer2)
// 	{
// 		free(buffer2);
// 		buffer2 = NULL;
// 	}
// 	return (0);
// }

static char	*setline(char *linebuf) // not freeing leftovers here properly??
{
	char *cursor;
	char *leftovers;
	
	cursor = linebuf;
	leftovers = 0;
	while (*cursor != '\n' && *cursor != '\0')
		cursor++;
	if (*cursor == '\n')
	{
		leftovers = ft_strdup(cursor + 1);
		*(cursor + 1) = '\0';
	}	
	else if (*cursor == '\0')
		leftovers = ft_strdup(""); // no strdup so freeing isn't necessary right after this
	return (leftovers); // if leftovers = 0, then this value will just be returned here.
} // return 0 ONLY on error here and empty-string if last line.  Have a check outside to reassign leftovers to 0 if empty. (no need to free old one)

static char	*buildlinebuf(char *leftovers, int fd, int *eofptr)
{
	int bytesread;
	int nlfound;
	char *buffer;

	bytesread = 0;
	nlfound = 0;
	if (fd < 0)
		return (0);
	while (*eofptr == 0 && nlfound == 0)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (buffer == 0)
			return (0);  // free THIS leftovers (which is the linebuf) here!
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (0); // free buffer and leftovers here!!
		else if (bytesread < BUFFER_SIZE && bytesread >= 0)
			*eofptr = 1;
		if (ft_strchr(buffer, '\n') != 0)
			nlfound = 1;
		if (bytesread > 0)
			leftovers = ft_strjoin(leftovers, buffer); // buffer and leftovers freed here in the case where buffer is non-empty
		//free(buffer); // if buffer is empty, just free it and keep leftovers as is.
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	char *linebuf;

	static char	*leftovers = 0;
	static int eof = 0;
	// static int leftinit = 0;
	if (fd < 0 || (eof == 1 && leftovers == 0))
		return (0);
	if (leftovers == 0)
	{
		leftovers = ft_strdup("");
		if (leftovers == 0)
			return (0);
	}
	else if (eof == 1 && leftovers != 0)
		return (leftovers);
	linebuf = buildlinebuf(leftovers, fd, &eof);
	if (linebuf == 0)
		return (0);  // might not have to free leftovers here bc if first read error, old leftovers freed.  If not, old leftovers freed after appending.
	leftovers = setline(linebuf); // we add old leftovers as parameter to free it before reassigning.....
	if (leftovers == 0)
		return (0);  // no need to free linebuf bc already done in setline
	// else if (eof == 1 && *leftovers == '\0')
	// 	free(leftovers);
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
		if (linebuf != 0)
			free(linebuf);
	}
	close(fd);
}