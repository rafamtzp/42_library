/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <rafamtz2001@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:48:07 by ramarti2          #+#    #+#             */
/*   Updated: 2025/04/03 16:48:28 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
#include <stdio.h>
size_t ft_strlcpy(char *dest, const char *src, size_t size);
int main(void)
{
    char *src = "helloooooo";
    char dest[100];
    unsigned int n = 5;

    unsigned int len = ft_strlcpy(dest, src, n);
    printf("This function tried copying %i chars from src.\n", len);
    for (unsigned int i = 0; i < n; i++)
    {
        if (dest[i] != '\0')
        {
            printf("%c\n", dest[i]);
        }
        else if (dest[i] == '\0')
        {
            printf("#\n");
        }
    }
}*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	n;
	unsigned int	len;
	const char			*initial;

	initial = src;
	len = 0;
	n = 0;
	while (*src != '\0')
	{
		len++;
		src++;
	}
	src = initial;
	if (size == 0)
		return (len);
	while (n < size - 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		n++;
	}
	*dst = '\0';
	return (len);
}
