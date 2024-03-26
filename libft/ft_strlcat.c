/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:47:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/01/09 14:02:28 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t buffersize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	space;

	srclen = ft_strlen(src);
	if ((buffersize == 0) && (!dest))
		return (srclen);
	destlen = ft_strlen(dest);
	if (buffersize <= destlen)
		return (buffersize + srclen);
	space = buffersize - destlen - 1;
	if (srclen <= space)
	{
		ft_memcpy(dest + destlen, src, srclen);
		dest[destlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dest + destlen, src, space);
		dest[buffersize - 1] = '\0';
	}
	return (destlen + srclen);
}
