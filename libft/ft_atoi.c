/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:17:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/01/02 19:58:17 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			negative;
	long		index;
	long long	longvalue;

	negative = 1;
	index = 0;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		longvalue = index;
		index = index * 10 + negative * (*str - 48);
		if (index > longvalue && negative < 0)
			return (0);
		if (index < longvalue && negative > 0)
			return (-1);
		str++;
	}
	return (index);
}
