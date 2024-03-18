/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:40:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/17 22:08:16 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_printptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_printptr(num / 16);
		ft_printptr(num % 16);
	}
	else
	{
		if (num <= 9)
			print_char(num + '0');
		else
			print_char(num - 10 + 'a');
	}
}

int	print_ptr(unsigned long long ptr)
{
	int	ptr_len;

	ptr_len = 0;
	ptr_len += write(1, "0x", 2);
	if (ptr == 0)
		ptr_len += write(1, "0", 1);
	else
	{
		ft_printptr(ptr);
		ptr_len += ft_ptrlen(ptr);
	}
	return (ptr_len);
}
