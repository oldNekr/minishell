/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:51 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:53 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void *ft_memchr(const void *s, int c, size_t n)
 *
 * Allocates (with malloc(3)) and returns a new
 * element. The variable ’content’ is initialized
 * with the value of the parameter ’content’. The
 * variable ’next’ is initialized to NULL.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(*t));
	if (t == NULL)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}
