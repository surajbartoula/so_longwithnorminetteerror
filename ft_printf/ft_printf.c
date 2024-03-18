/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:22:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/17 22:08:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_udigit(va_arg(ap, int));
	else if (specifier == 'x')
		count += print_hex(va_arg(ap, unsigned int), 0);
	else if (specifier == 'X')
		count += print_hex(va_arg(ap, unsigned int), 1);
	else if (specifier == '%')
		count += print_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
