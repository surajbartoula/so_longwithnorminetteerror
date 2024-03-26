/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:15:43 by sbartoul          #+#    #+#             */
/*   Updated: 2023/12/27 13:03:08 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	size_t	len;
	int		neg;

	len = 0;
	neg = 0;
	if (n < 0)
	{
		len++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_numtostr(char *str, long nbr, int len)
{
	int	neg;

	if (nbr != 0)
		str = malloc(sizeof(char) * (len + 1));
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	neg = 0;
	if (nbr < 0)
	{
		neg++;
		nbr = -nbr;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	else
		str[0] = (nbr % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	int		slen;
	char	*str;
	long	nbr;

	nbr = n;
	slen = ft_len(nbr);
	str = 0;
	str = ft_numtostr(str, nbr, slen);
	if (!str)
		return (0);
	return (str);
}
