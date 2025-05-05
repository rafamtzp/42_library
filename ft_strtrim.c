/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:56:47 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/02 21:01:42 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*startfind(char const *s1, char const *set);
char const	*endfind(char const *s1, char const *set, char const *start);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int			len;
	char const	*start;
	char const	*end;

	start = startfind(s1, set);
	end = endfind(s1, set, start);
	len = 0;
	while (&start[len] != end)
		len++;
	return (ft_substr(start, 0, len + 1));
}

char const	*startfind(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (!set[j])
			return (&s1[i]);
		i++;
	}
	return (0);
}

char const	*endfind(char const *s1, char const *set, char const *start)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && &s1[i] != start)
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (!set[j])
			return (&s1[i]);
		i--;
	}
	return (0);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	i = start;
	while (s[i] != '\0' && (i - start) < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int	main(void)
{
	char const *s = "tgytygtygyhello, worldgyyygytygyty";
	char const *set = "gty";

	printf("%s\n", ft_strtrim(s, set));
}*/