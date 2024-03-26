/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:26:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/01/09 14:05:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	char	*cdest;
	size_t	i;
	size_t	j;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!*src)
		return ((char *)dest);
	else if (n == 0)
		return (NULL);
	i = 0;
	cdest = (char *)dest;
	if (srclen == 0 || dest == src)
		return (cdest);
	while (cdest[i] != '\0' && i < n)
	{
		j = 0;
		while (cdest[i + j] != '\0' && src[j] != '\0'
			&& cdest[i + j] == src[j] && (i + j) < n)
			j++;
		if (j == srclen)
			return (cdest + i);
		i++;
	}
	return (0);
}
