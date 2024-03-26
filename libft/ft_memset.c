/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:19:27 by sbartoul          #+#    #+#             */
/*   Updated: 2023/12/19 19:12:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)string;
	while (len > 0)
	{
		*str = (unsigned char)c;
		len--;
		str++;
	}
	return (string);
}
