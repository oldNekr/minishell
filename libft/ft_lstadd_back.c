/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:07:54 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:11:55 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void	ft_lstadd_back(t_list **lst, t_list *new)
 *
 * Adds the element ’new’ at the end of the list.
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*begin;

	if (lst && new)
	{
		begin = *lst;
		if (begin == NULL)
			*lst = new;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
		}
	}
}
