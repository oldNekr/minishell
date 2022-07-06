/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:08:24 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 13:08:30 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* size_t ft_strlcat (char *dst, const char *src, size_t size)
*
* Copies and concatenates strings respectively. Appends the NUL-terminated
* string Fa src to the end of Fa dst . It will append
* at most Fa size - strlen(dst) - 1 bytes, NUL-terminating the result.
*
* Return: Total length of the string it tried to create.
*/

#include "libft.h"

static size_t	ft_concat(const char *s, int diff, char *d, const char *src)
{
	while (*s != '\0')
	{
		if (diff != 1)
		{
			*d++ = *s;
			diff--;
		}
		s++;
	}
	*d = '\0';
	return (s - src);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len;
	size_t		diff;

	d = dst;
	s = src;
	len = size;
	while (*d != '\0' && len != 0)
	{
		len--;
		d++;
	}
	len = d - dst;
	diff = size - len;
	if (diff == 0)
		return (len + ft_strlen(s));
	diff = ft_concat(s, diff, d, src);
	return (len + diff);
}
