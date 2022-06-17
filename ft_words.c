/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:29:40 by hgill             #+#    #+#             */
/*   Updated: 2022/06/17 15:35:52 by hgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_length(char character, int *l)
{
	write(1, &character, 1);
	(*l)++;
}

void	ft_string(char *args, int*l)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*l) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar_length(args[i], l);
		i++;
	}
}
