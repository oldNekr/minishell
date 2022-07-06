/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:58:46 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:58:47 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void	*ft_memcpy(void *dest, const void *src, size_t n)
 *
 * Copies n bytes from memory area src to
 * memory area dest. The memory areas must not overlap.
 *
 * Return: pointer to dest.
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	s = (const char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
