/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:09:58 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:10:00 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void *ft_calloc(size_t nmemb, size_t size)
 *
 * The ft_calloc() function shall allocate unused space for an array of
 * nmemb elements each of whose size in bytes is size.
 * The space shall be initialized to all bits 0.
 *
 * Return: a pointer to the allocated space.
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == 0)
		return (0);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
