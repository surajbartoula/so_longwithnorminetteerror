/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:42:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/01/09 14:13:24 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tdest;
	unsigned char	*tsrc;

	if (!src && !dest)
		return (NULL);
	tdest = (unsigned char *)dest;
	tsrc = (unsigned char *)src;
	if (dest <= src)
	{
		return (ft_memcpy(dest, src, len));
	}
	if (dest > src)
	{
		while (len > 0)
		{
			tdest[len - 1] = tsrc[len - 1];
			len--;
		}
	}
	return (dest);
}
