/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:08:48 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:08:49 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void	ft_lstclear(t_list **lst, void (*del)(void *))
 *
 * Deletes and frees the given element and every
 * successor of that element, using the function ’del’
 * and free(3).
 * Finally, the pointer to the list must be set to
 * NULL.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*l;

	if (del == NULL)
		return ;
	l = *lst;
	while (l)
	{
		if (l->next)
			tmp = l->next;
		else
			tmp = NULL;
		del(l->content);
		free(l);
		l = tmp;
	}
	*lst = NULL;
}
