/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:59:18 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:59:19 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void	*ft_memmove(void *dest, const void *src, size_t n)
 *
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap.
 *
 * Return: pointer to dest.
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		s = (const char *)src + (n - 1);
		d = (char *)dest + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
