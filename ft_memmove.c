/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:14:13 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/02 22:32:36 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s == 0 || d == 0)
		return (0);
	if (s < d && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[100] = "hello, world";
	printf("%s\n", src);
	ft_memmove(src + 7, src, 13);
	printf("%s\n", src);
}*/