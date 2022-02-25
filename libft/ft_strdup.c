/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:03:52 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:03:52 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, ULLONG_MAX);
	return (dst);
}
