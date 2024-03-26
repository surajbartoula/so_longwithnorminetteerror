/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:29:40 by sbartoul          #+#    #+#             */
/*   Updated: 2023/12/22 22:38:07 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	slen;

	slen = ft_strlen(str) + 1;
	ptr = malloc(sizeof(char) * slen);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, str, slen);
	return (ptr);
}
