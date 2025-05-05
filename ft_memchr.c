/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:58:47 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:57 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*cursor;

	ptr = 0;
	cursor = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*cursor == c)
		{
			ptr = cursor;
			return (ptr);
		}
		cursor++;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int main (void)
{
	char *s = "hello, cro how are u";
	char *find = ft_memchr(s, 'c', 21);
	printf("%s\n%s\n", s, find);

}*/
