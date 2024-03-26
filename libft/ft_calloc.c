/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:08:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/01/02 18:21:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	len;
	void	*ptr;

	if (size && (num > SIZE_MAX / size))
		return (NULL);
	len = num * size;
	ptr = malloc(len);
	if (!ptr)
		return (0);
	ft_bzero(ptr, len);
	return (ptr);
}
