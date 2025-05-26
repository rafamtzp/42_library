#include <stdlib.h>
#include <unistd.h>

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

char *appendbufs(char *left_c, int fd)
{
	char *buffer;
	int foundending;
	int	bytesread;

	// read BUFFER_SIZE chars in a loop until \n or \0 is found
	foundending = 0;
	while (foundending == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == 0)
			return (0);
		buffer[BUFFER_SIZE] = '\0';
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (0);
		// if there is another null char besides the terminator or a newline,
		else if (ft_strchr(buffer, '\0') < &buffer[BUFFER_SIZE] || ft_strchr(buffer, '\n') != 0) 
			foundending = 1; // realloc if first case so intermediate '\0' at the end
		// copy each buffer read into left_c
		if (*left_c != '\0') // if non-empty
			//append each buffer
			left_c = (char *)ft_strjoin(left_c, buffer);
		else // if empty, assign to buffer.
			left_c = ft_strdup(buffer);
		free(buffer);
	}
	return (left_c);
}

char *setline(char *linebuf)
{
	char *cursor;
	char *left_c;

	cursor = linebuf;
	// store remainder in left_c:
	// 1. move linebuf cursor until \n or \0
	while (*cursor != '\n' && *cursor != '\0')
		cursor++;
	// if in newline, move to one after it and store leftovers in left_c
	if (*cursor == '\n')
	{
		cursor++;
		left_c = ft_strdup(cursor);
	}
	// if at terminator, then eof reached and no leftovers. return empty string
	else
		left_c = "\0";
	// find \n and put a \0 after it
	*cursor = '\0';
	return (left_c);
}

char *get_next_line(int fd)
{
	static char *left_c;
	char	*linebuf;

	linebuf = appendbufs(left_c, fd);
	if (left_c == 0)
		return (0);
	
	left_c = setline(linebuf);
	if (left_c == 0)
		return (0);
	
	return (linebuf);
	// if \0 is found, free leftchars (right before return) (what was this????????)
}
// TOFIX: consider case where end of file comes early.  That is, when buffersize too large!!!!

// use strjoin
// ssize_t read(int fd, void *buf, size_t nbyte)
// returns the number of bytes read. Otherwise, -1
// always reads starting from the offset in the file (if supported)


// PREGUNTA: para qué la variable estatica?????

// -D BUFFER_SIZE=xx determina el tamaño del buffer de las lecturas del gnl
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}