/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:40:44 by hgill             #+#    #+#             */
/*   Updated: 2022/06/17 15:08:56 by hgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  void   ft_check_format(char c, va_list *args, int *l, int *i)
 {
     if (c == 's')
         ft_putstr_str(va_arg(*args, char *), l);
     else if (c == 'd' || c == 'i')
         ft_putnbr_d(va_arg(*args, int), l);
     else if (c == 'u')
         ft_uns(va_arg(*args, unsigned int), l);
     else if (c == 'x')
         ft_hex(va_arg(*args, unsigned int), l, 'x');
     else if (c == 'X')
         ft_hex(va_arg(*args, unsigned int), l, 'X');
     else if (c == 'p')
         ft_p(va_arg(*args, size_t), l);
     else if (c == 'c')
         ft_putchar_length(va_arg(*args, int), l);
     else if (c == '%')
         ft_putchar_length('%', l);
	 else
		 (*i)--;
 }

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int	i;
	int	l;

	i = 0;
	l = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_check_format(string[i], &args, &l, &i);
			i++;
		}
		else
		{
			ft_putchar_length((char)string[i], &l);
			i++;
		}
	}va_end(args);
	return (l);
}
