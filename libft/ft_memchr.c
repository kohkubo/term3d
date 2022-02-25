/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:03:16 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:03:17 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (0 < n && *(const unsigned char *)s != (unsigned char)c)
	{
		--n;
		++s;
	}
	if (n)
		return ((void *)s);
	else
		return (NULL);
}
