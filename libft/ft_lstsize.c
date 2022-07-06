/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:12:31 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:12:32 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * int		ft_lstsize(t_list *lst)
 *
 * Counts the number of elements in a list.
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*it;

	len = 0;
	it = lst;
	while (it)
	{
		len++;
		it = it->next;
	}
	return (len);
}
