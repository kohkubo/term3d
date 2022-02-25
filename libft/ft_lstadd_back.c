/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohkubo <kohkubo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:02:48 by kohkubo           #+#    #+#             */
/*   Updated: 2021/08/09 16:02:49 by kohkubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newobj)
{
	t_list	*last;

	if (!lst || !newobj)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = newobj;
	}
	else
		*lst = newobj;
}
