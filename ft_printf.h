/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:56:08 by hgill             #+#    #+#             */
/*   Updated: 2022/06/17 15:58:40 by hgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void			ft_putchar_length(char character, int *l);
void			ft_string(char *args, int *l);

void			ft_number(int num, int *l);
void			ft_hexadecimal(unsigned int x, int *l, chararacter);
void			ft_unsigned_int(unsigned int u, int *l);
void			ft_pointer(size_t pointer, int *l);

int				ft_printf(const char *string, ...);

#endif
