/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:06:35 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:06:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * char *ft_strrchr(const char *str, int c)
 *
 * Returns a pointer to the last occurrence
 * of the character c in the string str.
 *
 * Return: pointer to the matched character or NULL if the
 * character is not found.  The terminating null byte
 * is considered part of the string, so that if c is
 * specified as '\0', these functions return a
 * pointer to the terminator.
 */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*save;

	save = 0;
	while (1)
	{
		if (*str == (unsigned char)c)
			save = (char *)str;
		if (*str == '\0')
			return (save);
		str++;
	}
}
