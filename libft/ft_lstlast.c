/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:12:17 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:12:18 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * t_list	*ft_lstlast(t_list *lst)
 *
 * Returns the last element of the list.
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
