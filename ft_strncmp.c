/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:49:32 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/02 21:01:54 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0' || *s2 == '\0')
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int ft_strncmp(const char *s1, const char *s2, size_t n);
int main(void)
{
    char *s1 = "hello";
    char *s2 = "helloa";
    unsigned int n = 74;
    printf("%i\n", ft_strncmp(s1, s2, n));
    printf("%i\n", strncmp(s1, s2, n));
}*/