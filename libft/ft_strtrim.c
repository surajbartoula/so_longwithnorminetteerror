/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:46:22 by sbartoul          #+#    #+#             */
/*   Updated: 2023/12/24 19:08:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_chr_avl(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1len;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	s1len = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	while (is_chr_avl(s1[i], set) == 1)
		i++;
	if (i == s1len)
	{
		str = ft_strdup("");
		if (!str)
			return (0);
		else
			return (str);
	}
	while (is_chr_avl(s1[s1len - 1], set) == 1)
		s1len--;
	str = ft_substr(s1, i, s1len - i);
	return (str);
}
