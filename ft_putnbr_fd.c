/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramarti2 <ramarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:11:13 by ramarti2          #+#    #+#             */
/*   Updated: 2025/05/02 21:11:25 by ramarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sizecalc(int n)
{
	int				size;
	unsigned int	temp_n;

	if (n < 0)
		temp_n = -n;
	else if (n > 0)
		temp_n = n;
	else
		return (1);
	size = 0;
	while (temp_n > 0)
	{
		temp_n = temp_n / 10;
		size++;
	}
	return (size);
}

int	isnegative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				size;
	int				i;
	int				isneg;
	unsigned int	num;

	size = sizecalc(n);
	isneg = isnegative(n);
	if (isneg == 1)
		write(fd, "-", 1);
	while (size > 0)
	{
		if (isneg == 1)
			num = -n;
		else
			num = n;
		i = size - 1;
		while (i > 0)
		{
			num = num / 10;
			i--;
		}
		num = num % 10 + '0';
		write(fd, &num, 1);
		size--;
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-58232559, 1);
}*/