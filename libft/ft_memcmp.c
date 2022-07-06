/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:08:29 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:08:30 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * int ft_memcmp(const void *s1, const void *s2, size_t n)
 *
 * Compares the first n bytes (each interpreted as unsigned char)
 * of the memory areas s1 and s2.
 *
 * Return: an integer less than, equal to, or greater than zero
 * if the first n bytes of s1 is found, respectively,
 * to be less than, to match, or be greater
 * than the first n bytes of s2.
 * If n is zero, the return value is zero.
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
