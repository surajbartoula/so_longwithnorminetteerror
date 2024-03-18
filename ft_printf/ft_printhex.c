/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:21:05 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/17 22:08:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(long num, int uppercase)
{
	int		count;
	char	*symbols;

	if (!uppercase)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (num < 0)
	{
		print_char('-');
		return (print_hex(-num, uppercase) + 1);
	}
	else if (num < 16)
	{
		return (print_char(symbols[num]));
	}
	else
	{
		count = print_hex((num / 16), uppercase);
		return (count + print_hex((num % 16), uppercase));
	}
}
