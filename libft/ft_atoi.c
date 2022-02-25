/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:02:27 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/29 13:32:00 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* \t \n \v \f \r ' ' */
static int	ft_isspace(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

static int	ft_atoi_overflow(int neg)
{
	errno = EINVAL;
	if (neg == 1)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

int	ft_atoi(const char *s)
{
	unsigned long	n;
	int				neg;
	unsigned long	tmp;

	n = 0;
	neg = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			neg = -1;
	while (ft_isdigit(*s))
	{
		tmp = n;
		n = n * 10 + *s++ - '0';
		if (tmp >> 60 || n >> 63)
			return (ft_atoi_overflow(neg));
	}
	if (n > INT_MAX || (n == (unsigned long)INT_MAX + 1 && neg == -1))
		errno = EINVAL;
	return ((int)(n * neg));
}
