/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_ber_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:48:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/02 16:11:35 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_double_ext(char *str)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

int	has_ber_extension(char *filename)
{
	char		*extension;
	size_t		filename_len;
	size_t		extension_len;
	char		*file_extensn;

	extension = ".ber";
	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (filename_len < extension_len)
		return (0);
	file_extensn = filename + (filename_len - extension_len);
	if (ft_strcmp(file_extensn, extension) != 0 || ft_double_ext(filename) > 1)
		return (0);
	return (1);
}
