/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:08:01 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:08:02 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void *ft_memchr(const void *s, int c, size_t n)
 *
 * The memchr() function scans the initial n bytes of the memory
 * area pointed to by s for the first instance of c.
 * Both c and the bytes of the memory area
 * pointed to by s are interpreted as unsigned char.
 *
 * Return: pointer to the matching byte or
 * NULL if the character does not occur
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;

	src = (const unsigned char *)s;
	while (n--)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (0);
}
