/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:05:52 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/02 21:05:59 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	dstlen;
	int	srccount;
	int	limit;

	dstlen = 0;
	while (*dst)
	{
		dstlen++;
		dst++;
	}
	srccount = 0;
	limit = size - dstlen - 1;
	while (*src && srccount < limit)
	{
		*dst = *src;
		dst++;
		src++;
		srccount++;
	}
	while (*src)
		srccount++;
	*dst = '\0';
	return (srccount + dstlen);
}
/*
#include <stdio.h>

int	main(void)
{
	char dst[100] = "hello, ";
	char *src = "world";
	printf("resulting string has %zu chars\n", ft_strlcat(dst, src, 5 + 7 + 1));
	printf("%s\n", dst);
}*/