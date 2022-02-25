/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:02:45 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:02:46 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	n = n / 10;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		index;
	int		flg;
	long	nl;

	nl = (long)n;
	index = digit_len(n);
	flg = 0;
	str = (char *)malloc(sizeof(char) * index + 1);
	if (!str)
		return (0);
	str[index] = '\0';
	if (nl < 0)
	{
		flg = 1;
		nl *= -1;
	}
	while (0 < index)
	{
		str[--index] = nl % 10 + '0';
		nl /= 10;
	}
	if (flg)
		str[0] = '-';
	return (str);
}
