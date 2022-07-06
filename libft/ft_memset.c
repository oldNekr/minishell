/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:58:03 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:58:05 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * void	*ft_memset(void *s, int c, size_t n)
 *
 * Fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * Return: pointer to the memory area s.
 */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}
