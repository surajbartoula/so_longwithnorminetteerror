/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:21:05 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/17 22:07:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long num)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (num < 0)
	{
		print_char('-');
		return (print_digit(-num) + 1);
	}
	else if (num < 10)
	{
		return (print_char(symbols[num]));
	}
	else
	{
		count = print_digit((num / 10));
		return (count + print_digit((num % 10)));
	}
}

int	print_udigit(unsigned int num)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (num < 0)
	{
		print_char('-');
		return (print_udigit(-num) + 1);
	}
	else if (num < 10)
	{
		return (print_char(symbols[num]));
	}
	else
	{
		count = print_udigit((num / 10));
		return (count + print_udigit((num % 10)));
	}
}
