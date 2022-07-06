/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:15 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:17 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * char *ft_strchr(const char *str, int c)
 *
 * Returns a pointer to the first occurrence
 * of the character c in the string str.
 *
 * Return: pointer to the matched character or NULL if the
 * character is not found.  The terminating null byte
 * is considered part of the string, so that if c is
 * specified as '\0', these functions return a
 * pointer to the terminator.
 */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str_copy;

	str_copy = (char *)str;
	while (1)
	{
		if (*str_copy == (unsigned char)c)
			return ((char *)str_copy);
		if (*str_copy == '\0')
			return (0);
		str_copy++;
	}
}
