/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:28:44 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 14:28:47 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* s1 - The string to be trimmed.
* set - The reference set of characters to trim.
*
* Description Allocates (with malloc(3)) and returns a copy of
* ’s1’ with the characters specified in ’set’ removed
* from the beginning and the end of the string.
*
* Return value The trimmed string. NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	newstring = ft_substr((char *)s1, 0, size_s + 1);
	return (newstring);
}
