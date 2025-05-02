/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <rafamtz2001@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:17:13 by ramarti2          #+#    #+#             */
/*   Updated: 2025/03/27 14:17:50 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str);

int main(void){
    const char *s = "Hello";
    printf("%zu\n", ft_strlen(s));

}
*/

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
