/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:05:52 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/06 19:06:18 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	limit;

	dstlen = 0;
	while (*(dst++) && dstlen < size)
		dstlen++;
	srclen = 0;
	while (*(src++))
		srclen++;
	if (size <= dstlen + 1)
		return (srclen + dstlen);
	limit = size - dstlen - 1;
	while (*src && srclen < limit)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (srclen + dstlen);
}
/*
#include <stdio.h>

int	main(void)
{
	char dst[100] = "hello, ";
	char *src = "world";
	printf("resulting string has %zu chars\n", ft_strlcat(dst, src, 2));
	printf("%s\n", dst);
}*/