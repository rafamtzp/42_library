/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:22:21 by ramarti2          #+#    #+#             */
/*   Updated: 2025/06/11 17:24:37 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	long long		result;
	size_t			i;
	unsigned char	*ptr2;

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
	ptr2 = (unsigned char *)ptr;
	i = 0;
	while (i < (nmemb * size))
	{
		*ptr2 = '\0';
		ptr2++;
		i++;
	}
	return (ptr);
}

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

char	*ft_strdup(const char *s)
{
	char			*ptr;
	size_t			len;
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (ptr == 0)
		return (0);
	if (ptr == 0 && s == 0 && len + 1 > 0)
		return (0);
	ptr1 = (unsigned char *)s;
	ptr2 = (unsigned char *)ptr;
	i = 0;
	while (i < len + 1)
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
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
