/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:03:14 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:03:14 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*d;
	unsigned char	*s;

	uc = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (0 < n--)
	{
		*d = *s;
		if (*d == uc)
			return ((void *)(d + 1));
		d++;
		s++;
	}
	return (NULL);
}
