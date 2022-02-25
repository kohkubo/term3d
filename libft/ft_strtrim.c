/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:05:19 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:05:19 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s;
	char		*head;
	char const	*end;

	if (!s1 && !set)
		return (NULL);
	while (s1 && ft_cmp(*s1, set))
		s1++;
	end = s1 + ft_strlen(s1) - 1;
	while (s1 < end && ft_cmp(*end, set))
		end--;
	s = (char *)malloc(sizeof(char) * ((end - s1) + 2));
	if (!s)
		return (NULL);
	head = s;
	while (s1 <= end)
		*s++ = *s1++;
	*s = '\0';
	return (head);
}
