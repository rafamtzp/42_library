/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:00:18 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/07 17:53:37 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	wordlen(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static unsigned int	wordcounter(char const *s, char c)
{
	unsigned int	wordcount;
	int				firstfound;

	wordcount = 0;
	firstfound = 0;
	while (*s)
	{
		if (*s != c && firstfound == 0)
		{
			firstfound = 1;
			wordcount++;
		}
		else if (*s == c)
			firstfound = 0;
		s++;
	}
	return (wordcount);
}

static char	**kill(char **split, int i)
{
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (0);
}

static char	**splitfill(char **split, char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (*s)
	{
		len = wordlen(s, c);
		if (len > 0)
		{
			split[i] = malloc(len + 1);
			if (split == 0)
			{
				kill(split, i);
				return (0);
			}
			ft_strlcpy(split[i], s, len + 1);
			s += len - 1;
			i++;
		}
		s++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	wordcount;
	char			**split;

	wordcount = wordcounter(s, c);
	split = malloc(wordcount * sizeof(char *));
	if (split == 0)
		return (0);
	split = splitfill(split, s, c);
	return (split);
}
/*
#include <stdio.h>
int	main(void)
{
	char **split = ft_split("hello, world. How are you?", ' ');
	for (unsigned int i = 0; i < wordcounter("hello, world. How are you?",
			' '); i++)
		printf("%s\n", split[i]);
}*/