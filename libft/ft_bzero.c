/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:58:22 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:58:24 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void	ft_bzero(void * s , size_t  n)
 *
 * Erases the data in the n bytes of the memory
 * starting at the location pointed to by s,
 * by writing zeros (bytes containing '\0') to that area.
 *
 * Return: None.
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
