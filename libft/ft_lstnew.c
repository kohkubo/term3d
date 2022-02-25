/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:03:08 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:03:08 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
	{
		ft_putstr_fd("ft_lstnew: malloc failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
