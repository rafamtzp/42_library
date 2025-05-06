/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:56:25 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/06 19:50:43 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start > len)
		return (0);	
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	sub[len] = '\0';
	i = start;
	while (s[i] != '\0' && (i - start) < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	char const *s = "hello, world xxxxxx";
	unsigned int start = 7;
	size_t len = 5;
	printf("%s\n", ft_substr(s, start, len));
}*/