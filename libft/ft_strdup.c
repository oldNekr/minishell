/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:10:18 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:10:19 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* char	*ft_strdup(const char *s)
*
* Returns a pointer to a new string which is
* a duplicate of the string s.
*
* Return: On success, the strdup() function returns a pointer
* to the duplicated string. It returns NULL if
* insufficient memory was available
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s) + 1;
	result = malloc(size);
	if (result == 0)
		return (0);
	return ((char *)ft_memcpy(result, s, size));
}
