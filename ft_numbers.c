/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:34:48 by hgill             #+#    #+#             */
/*   Updated: 2022/06/17 15:54:45 by hgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int num, int*l)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*l) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putchar_length('-', l);
		ft_number(num * -1, l);
	}
	else
	{
		if (num > 9)
			ft_number(num / 10, l);
		ft_putchar_length(num % 10 + '0', l);
	}
}

void	ft_pointer(size_t pointer, int*l)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*l) += 2;
	if (pointer == 0)
	{
		ft_putchar_length('0', l);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar_length(string[i], l);
	}
}

void	ft_hexadecimal(unsigned int x, int *l, char character)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (character == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_length('0', l);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_length(string[i], l);
}

void	ft_unsigned_int(unsigned int u, int *l)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, l);
	ft_putchar_length(u % 10 + '0', l);
}
