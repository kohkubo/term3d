/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:03:21 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:03:21 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*head;

	head = dst;
	if (!src && !dst)
		return (NULL);
	while (0 < n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (head);
}
